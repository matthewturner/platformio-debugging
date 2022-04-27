#include <unity.h>
#include <ArduinoFake.h>
#include "Dependency.h"

using namespace fakeit;

Dependency dependency;

void test_method(void)
{
    bool actual = dependency.method();
    TEST_ASSERT_TRUE(actual);
}

void test_fake(void)
{
    When(Method(ArduinoFake(), millis)).AlwaysReturn(10);
    TEST_ASSERT_EQUAL(10, millis());
    TEST_ASSERT_EQUAL(10, millis());
}

void test_platform_method(void)
{
    When(Method(ArduinoFake(), millis)).AlwaysReturn(10);
    TEST_ASSERT_EQUAL(10, dependency.time());
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(test_method);
    RUN_TEST(test_fake);
    RUN_TEST(test_platform_method);
    UNITY_END();

    return 0;
}