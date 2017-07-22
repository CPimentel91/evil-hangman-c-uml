#include <stdio.h>
#include "unit_test.h"

int main(int argc, char* argv[])
{

    Status (*tests[])(char*, int) =
    {
    test_cpimente_init_default_returns_nonNULL,
    test_cpimente_get_size_on_init_default_returns_0,
    test_cpimente_get_capacity_on_init_default_returns_non0,
    test_cpimente_size_increase_after_pushback,
    test_cpimente_size_decrease_after_popback,
    test_cpimente_resize_push_back,
    test_cpimente_size_increase_concat,
    test_cpimente_destroy_returns_NULL,
    test_cpimente_c_string_size_unchanged,
    test_cpimente_c_string_capacity_increased,
    test_cpimente_c_string_compare_equal_returns_0,
    test_cpimente_c_string_compare_left_greater_returns_greater_than_0,
    test_cpimente_c_string_compare_left_smaller_returns_less_than_0,
    test_cpimente_my_string_at_returns_valid_index,
    test_cpimente_my_string_at_invalid_index_returns_NULL,
    test_cpimente_popback_returns_failure_if_empty,
    test_cpimente_c_string_NULL_terminated,
    test_cpimente_init_c_string_returns_nonNULL,
    test_cpimente_string_insertion_returns_failure_given_empty_object,
    test_cpimente_string_empty_returns_true_if_given_empty_string,
    test_cpimente_capacity_increase_after_pushback,
    test_cpimente_capacity_unchanged_after_popback,
    test_cpimente_string_extraction_data_returns_nonNULL,
    test_cpimente_string_extraction_get_size,
    test_cpimente_string_extraction_return_failure_if_file_empty
    };
    int number_of_functions = sizeof(tests) / sizeof(tests[0]);
    int i;
    char buffer[500];
    int success_count = 0;
    int failure_count = 0;

    for (i = 0; i < number_of_functions; i++)
    {

        if(tests[i](buffer, 500) == FAILURE)
        {
            printf("FAILED: Test %d failed miserably\n", i);
            printf("\t%s\n", buffer);
            failure_count++;
        }

        else

        {
        printf("PASS: Test %d passed\n", i);
        printf("\t%s\n", buffer);
        success_count++;
        }
    }

    printf("Total number of tests: %d\n", number_of_functions);
    printf("%d/%d Pass, %d/%d Failure\n", success_count,
    number_of_functions, failure_count, number_of_functions);

    return 0;
}



