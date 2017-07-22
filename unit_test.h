#include "my_string.h"

Status test_cpimente_init_default_returns_nonNULL(char* buffer, int length);

Status test_cpimente_get_size_on_init_default_returns_0(char* buffer, int length);

Status test_cpimente_get_capacity_on_init_default_returns_non0(char* buffer, int length);

Status test_cpimente_size_increase_after_pushback(char* buffer, int length);

Status test_cpimente_size_decrease_after_popback(char* buffer, int length);

Status test_cpimente_resize_push_back(char* buffer, int length);

Status test_cpimente_size_increase_concat(char* buffer, int length);

Status test_cpimente_destroy_returns_NULL(char* buffer, int length);

Status test_cpimente_c_string_size_unchanged(char* buffer, int length);

Status test_cpimente_c_string_capacity_increased(char* buffer, int length);

Status test_cpimente_c_string_compare_equal_returns_0(char* buffer, int length);

Status test_cpimente_c_string_compare_left_greater_returns_greater_than_0(char* buffer, int length);

Status test_cpimente_c_string_compare_left_smaller_returns_less_than_0(char* buffer, int length);

Status test_cpimente_my_string_at_returns_valid_index(char* buffer, int length);

Status test_cpimente_my_string_at_invalid_index_returns_NULL(char* buffer, int length);

Status test_cpimente_popback_returns_failure_if_empty(char* buffer, int length);

Status test_cpimente_c_string_NULL_terminated(char* buffer, int length);

Status test_cpimente_init_c_string_returns_nonNULL(char* buffer, int length);

Status test_cpimente_string_insertion_returns_failure_given_empty_object(char* buffer, int length);

Status test_cpimente_string_empty_returns_true_if_given_empty_string(char* buffer, int length);

Status test_cpimente_capacity_increase_after_pushback(char* buffer, int length);

Status test_cpimente_capacity_unchanged_after_popback(char* buffer, int length);

Status test_cpimente_string_extraction_data_returns_nonNULL(char* buffer, int length);

Status test_cpimente_string_extraction_get_size(char* buffer, int length);

Status test_cpimente_string_extraction_return_failure_if_file_empty(char* buffer, int length);



