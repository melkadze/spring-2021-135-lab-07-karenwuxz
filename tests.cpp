#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "unindent.h"
#include "indent.h"

TEST_CASE("removingLeadingSpaces") {
    // this function adds a newline to the result for later functionality,
    // compensating for that by adding \n to right-side comparison
    
    CHECK(removingLeadingSpaces("no leading space") == "no leading space\n");
    CHECK(removingLeadingSpaces(" one leading space") == "one leading space\n");
    CHECK(removingLeadingSpaces("      multiple leading spaces") == "multiple leading spaces\n");
    CHECK(removingLeadingSpaces("          multiple leading and trailing spaces   ") == "multiple leading and trailing spaces   \n");
}

TEST_CASE("unindent") {
    // using unindentTesting, which is just unindent() with input support
    
    CHECK(unindentTesting("no leading space\n one leading space\n     multiple leading spaces\n") == "no leading space\none leading space\nmultiple leading spaces\n");
    CHECK(unindentTesting("     lines with same indent\n     lines with same indent\n     lines with same indent\n") == "lines with same indent\nlines with same indent\nlines with same indent\n");
}

TEST_CASE("countChar") {
    CHECK(countChar("abcdef", 'a') == 1);
    CHECK(countChar("12113111", '1') == 6);
    CHECK(countChar("123456", 'x') == 0);
    CHECK(countChar("{{}}", '{') == 2);
}

TEST_CASE("formatting") {
    // using formattingTesting, which is just formatting() with input support
    
    CHECK(formattingTesting("        int main(){\n// Hi, I'm a program!\n  int x = 1; \nfor(int i = 0; i < 10; i++) {\ncout << i;\n         cout << endl;\n}\n}") == "int main(){\n\t// Hi, I'm a program!\n\tint x = 1; \n\tfor(int i = 0; i < 10; i++) {\n\t\tcout << i;\n\t\tcout << endl;\n\t}\n}\n");
    CHECK(formattingTesting("   int x = 1") == "int x = 1\n");
    CHECK(formattingTesting("  while(true){\n           break;\n }") == "while(true){\n\tbreak;\n}\n");
}