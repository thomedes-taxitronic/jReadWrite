#include "jWrite.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>


static bool test_readme_example_1(void) {
    bool ok = true;
    static const char expected_result[] =
        "{\n"
        "    \"key\": \"value\",\n"
        "    \"int\": 1,\n"
        "    \"anArray\": [\n"
        "        0,\n"
        "        1,\n"
        "        2\n"
        "    ]\n"
        "}";
    char buffer[128];
    const size_t buflen = sizeof buffer;
    int err;

    struct jWriteControl jwc;
    jwOpen( &jwc, buffer, buflen, JW_OBJECT, JW_PRETTY );  // open root node as object
    jwObj_string( &jwc, "key", "value" );                  // writes "key":"value"
    jwObj_int( &jwc, "int", 1 );                           // writes "int":1
    jwObj_array( &jwc, "anArray");                         // start "anArray": [...]
        jwArr_int( &jwc, 0 );                              // add a few integers to the array
        jwArr_int( &jwc, 1 );
        jwArr_int( &jwc, 2 );
    jwEnd( &jwc );                                         // end the array
    err= jwClose( &jwc );                                  // close root object - done

    ok = strncmp(expected_result, buffer, buflen) == 0;
    if (!ok) {
        fprintf(stderr, "Invalid result: %d ->\n'%s'\n", err, buffer);
    }
    return ok;
}


int main(int argc, char *argv[]) {
    bool ok = test_readme_example_1();

    (void) argc;
    (void) argv;

    return ok ? 0 : 1;
}
