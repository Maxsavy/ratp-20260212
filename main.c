
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include "cmocka.h"
#include <string.h>
#include "ratp.h"
#include "age.h"

// définitions setup et teardown
static int setup(void **state)
{
    (void)state;
    //   printf("setUp");
    return 0;
}

static int setup2(void **state)
{
    (void)state;
    //   printf("setUp2");
    return 0;
}

static int teardown(void **state)
{
    (void)state;
    //   printf("tearDown");
    return 0;
}

// tests sur computePrice
void recupAge(int *age)
{
    function_called();
    *age = (int)mock();
}

static void null_test_pas_touriste_pas_enfant(void **state)
{
    (void)state;
    expect_function_calls(recupAge, 1);
    will_return(recupAge, 12);
    assert_float_equal(computePrice(30, 0), 1.5, 0.0001);
}

static void null_test_touriste_pas_enfant(void **state)
{
    (void)state;
    expect_function_calls(recupAge, 1);
    will_return(recupAge, 12);
    assert_float_equal(computePrice(30, 1), 3, 0.0001);
}

static void null_test_touriste_enfant_equal(void **state)
{
    (void)state;
    expect_function_calls(recupAge, 1);
    will_return(recupAge, 12);
    assert_true(computePrice(6, 1) == 1.5);
}

static void null_test_pas_touriste_enfant_equal(void **state)
{
    (void)state;
    expect_function_calls(recupAge, 1);
    will_return(recupAge, 12);
    assert_true(computePrice(6, 0) == 0.75);
}

// tests simples de succes et echecs
static void null_test_success(void **state)
{
    (void)state;
}

static void null_test_fail_avec_msg(void **state)
{
    (void)state;
    fail_msg("failed");
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test_setup(null_test_success, setup2),
        cmocka_unit_test_setup_teardown(null_test_pas_touriste_pas_enfant, setup2, teardown),
        cmocka_unit_test(null_test_touriste_pas_enfant),
        cmocka_unit_test(null_test_touriste_enfant_equal),
        cmocka_unit_test(null_test_pas_touriste_enfant_equal),
        cmocka_unit_test(null_test_fail_avec_msg),
    };
    cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests_name("Tests TP2", tests, setup, teardown);
}