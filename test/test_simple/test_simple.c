#include "unity.h"
void setUp(void) {}

void tearDown(void) {}

void test1(){
    TEST_ASSERT_EQUAL(2,2);
}
int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test1);
  //RUN_TEST(test_led_init_only_the_7th_bit_is_set);

  return UNITY_END();
}