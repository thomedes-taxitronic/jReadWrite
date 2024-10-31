#include "jRead.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

static const char pJson[]
    = "{\n"
      "    \"astring\":\"This is a string\",\n"
      "    \"anumber\":42,\n"
      "    \"myarray\":[ \"zero\", 1, {\"description\":\"element 2\"}, null "
      "],\n"
      "    \"yesno\":true,\n"
      "    \"PI\":\"3.1415926\",\n"
      "    \"foo\":null\n"
      "}\n";

static bool check_element(
    struct jReadElement obj,
    int                 dataType, // one of JREAD_...
    int elements, // number of elements (e.g. elements in array or object)
    int bytelen, // byte length of element (e.g. length of string, array text "[
                 // ... ]" etc.)
    const char* pValue, // pointer to value string in JSON text
    int         error   // error value if dataType == JREAD_ERROR
) {
    bool ok
        = ((obj.dataType == dataType) && (obj.elements == elements)
           && (obj.bytelen == bytelen) && (memcmp(obj.pValue, pValue, bytelen) == 0)
           && (obj.error == error));
    if (!ok) {
        fprintf(
            stderr,
            "Element check failed!\n"
            "- Expected: { %d, %d, %d, \"%s\", %d }\n"
            "- Got:      { %d, %d, %d, \"%.*s\", %d }\n",
            dataType,
            elements,
            bytelen,
            pValue,
            error,
            obj.dataType,
            obj.elements,
            obj.bytelen,
            bytelen,
            (const char *) obj.pValue,
            obj.error
        );
    }
    return ok;
}

static bool test_readme_example_1(void) {
    bool                ok = true;
    struct jReadElement result;

    jRead(pJson, "{'astring'", &result);

    ok = check_element(result, JREAD_STRING, 1, 16, "This is a string", 0);

    return ok;
}

int main(int argc, char* argv[]) {
    bool ok = test_readme_example_1();

    (void)argc;
    (void)argv;

    return ok ? 0 : 1;
}
