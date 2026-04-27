#include <unity.h>
#ifdef ARDUINO
#include <Arduino.h>
#endif

void setUp(void) {
}

void tearDown(void) {
}

void test_placeholder(void) {
    TEST_ASSERT_TRUE(true);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_placeholder);
    UNITY_END();
    return 0;
}
