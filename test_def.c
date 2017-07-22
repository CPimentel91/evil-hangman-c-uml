#include <stdio.h>
#include <stdlib.h>
#include "unit_test.h"
#include <string.h>


Status test_cpimente_init_default_returns_nonNULL(char* buffer, int length)
{
    MY_STRING hString = NULL;
    hString = my_string_init_default();
    if(hString == NULL)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_init_default_returns_nonNULL\n" "my_string_init_default returns NULL", length);
        return FAILURE;
    }

    else
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_init_default_returns_nonNULL\n", length);
        return SUCCESS;
    }
}
Status test_cpimente_get_size_on_init_default_returns_0(char* buffer, int length)
{
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();
    if(my_string_get_size(hString) != 0)
    {
        status = FAILURE;
        printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
        strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
        "Did not receive 0 from get_size after init_default\n", length);
    }

    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_get_size_on_init_default_returns_0\n", length);
    }

    my_string_destroy(&hString);
    return status;
}

Status test_cpimente_get_capacity_on_init_default_returns_non0(char* buffer, int length)
{
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();
    if (my_string_get_capacity(hString) != 0)
    {
        status = SUCCESS;
        strncpy(buffer, "get_capacity_on_init_default_returns_non0\n", length);
    }

    else
    {
        status = FAILURE;
        strncpy(buffer, "test_get_capacity_on_init_default_returns_0\n"
                "expected capacity greater than 0\n", length);
    }

    my_string_destroy(&hString);
    return status;
}

Status test_cpimente_size_increase_after_pushback(char* buffer, int length)
{
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();
    my_string_push_back(hString, 'a');
    if (my_string_get_size(hString) != 0)
    {
        status = SUCCESS;
        strncpy(buffer, "test_cpimente_size_increase_after_pushback\n"
                "size has increased after push_back operation\n", length);
    }

    else
    {
        status = FAILURE;
        strncpy(buffer, "test_cpimente_size_increase_after_pushback\n"
                "expected size greater than 0\n", length);
    }

    my_string_destroy(&hString);

    return status;
}

Status test_cpimente_size_decrease_after_popback(char* buffer, int length)
{
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();
    my_string_push_back(hString, 'a');

    my_string_pop_back(hString);
    if (my_string_get_size(hString) != 0)
    {
        status = FAILURE;
        strncpy(buffer,"test_cpimente_size_decrease_after_popback\n"
                "size has not decreased after pop_back operation\n", length);
    }

    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_cpimente_size_decrease_after_popback\n"
                "size has decreased after pop_back operation\n", length);
    }

    my_string_destroy(&hString);

    return status;
}

Status test_cpimente_resize_push_back(char* buffer, int length)
{
    MY_STRING hString = NULL;
    Status status;
    int before;
    int after;
    int i;

    hString = my_string_init_default();
    before = my_string_get_capacity(hString);
    for (i = 0; i < 500; i++)
    {
        my_string_push_back(hString, 'a');
    }
    after = my_string_get_capacity(hString);

    if (before == after)
    {
        status = FAILURE;
        strncpy(buffer,"test_cpimente_resize_push_back\n"
                "failed to resize on push_back\n", length);
    }

    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_cpimente_resize_push_back\n"
                "resize successful on push_back operation\n", length);
    }

    my_string_destroy(&hString);

    return status;
}

Status test_cpimente_size_increase_concat(char* buffer, int length)
{
    MY_STRING hString = NULL;
    MY_STRING hAppend = NULL;
    Status status;
    int left;
    int right;
    int sum;
    int i;

    hString = my_string_init_default();
    hAppend = my_string_init_default();
    for (i = 0; i < 10; i++)
    {
        my_string_push_back(hAppend, 'a');
    }

    for (i = 0; i < 10; i++)
    {
        my_string_push_back(hString, 'a');
    }

    left =  my_string_get_size(hString);
    right = my_string_get_size(hAppend);
    sum = left + right;
    my_string_concat(hString, hAppend);
    left = my_string_get_size(hString);

    if (sum != left)
    {
        status = FAILURE;
        strncpy(buffer,"test_cpimente_size_increase_concat\n"
                "failed to properly concatenate two strings\n", length);
    }

    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_cpimente_size_increase_concat\n"
                "successfully concatenated two strings\n", length);
    }

    my_string_destroy(&hString);
    my_string_destroy(&hAppend);

    return status;
}

Status test_cpimente_destroy_returns_NULL(char* buffer, int length)
{
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();
    my_string_destroy(&hString);

    if (hString != NULL)
    {
        status = FAILURE;
        strncpy(buffer,"test_cpimente_destroy_returns_NULL\n"
                "failed to properly destroy string object\n", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_cpimente_destroy_returns_NULL\n"
                "successfully destroyed string object\n", length);
    }
    return status;
}

Status test_cpimente_c_string_size_unchanged(char* buffer, int length)
{
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();
    my_string_c_str(hString);

    if (my_string_get_size(hString) != 0)
    {
        status = FAILURE;
        strncpy(buffer,"test_cpimente_c_string_size_unchanged\n"
                "addition of null terminator has increased size\n", length);
    }

    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_cpimente_c_string_size_unchanged\n"
                "null terminator added without increasing size\n", length);
    }


    my_string_destroy(&hString);

    return status;
}

Status test_cpimente_c_string_capacity_increased(char* buffer, int length)
{
    MY_STRING hString = NULL;
    Status status;
    int capacity;
    int after;
    int i;

    hString = my_string_init_default();

    for (i = 0; i < my_string_get_capacity(hString); i++)
    {
        my_string_push_back(hString, 'a');
    }
    capacity = my_string_get_capacity(hString);
    my_string_c_str(hString);
    after = my_string_get_capacity(hString);

    if (capacity == after)
    {
        status = FAILURE;
        strncpy(buffer,"test_cpimente_c_string_capacity_increased\n"
                "addition of null terminator did not increase capacity\n", length);
    }

    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_cpimente_c_string_capacity_increased\n"
                "capacity has increased with the addition of the null terminator\n", length);
    }

    my_string_destroy(&hString);

    return status;
}

Status test_cpimente_c_string_compare_equal_returns_0(char* buffer, int length)
{
    MY_STRING hLeft_string = NULL;
    MY_STRING hRight_string = NULL;
    Status status;

    hLeft_string = my_string_init_c_string("apple");
    hRight_string = my_string_init_c_string("apple");

    if (my_string_compare(hLeft_string, hRight_string) != 0)
    {
        status = FAILURE;
        strncpy(buffer,"test_cpimente_c_string_compare_equal\n"
                "string compare did not return 0\n", length);
    }

    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_cpimente_c_string_compare_equal\n"
                "string compare returned 0 when comparing two lexicographically equal strings\n", length);
    }

    my_string_destroy(&hLeft_string);
    my_string_destroy(&hRight_string);

    return status;

}

Status test_cpimente_c_string_compare_left_greater_returns_greater_than_0(char* buffer, int length)
{
    MY_STRING hLeft_string = NULL;
    MY_STRING hRight_string = NULL;
    Status status;

    hLeft_string = my_string_init_c_string("apple");
    hRight_string = my_string_init_c_string("app");

    if (my_string_compare(hLeft_string, hRight_string) <= 0)
    {
        status = FAILURE;
        strncpy(buffer,"test_cpimente_c_string_compare_left_greater_returns_greater_than_0\n"
                "string compare did not return value greater than 0\n", length);
    }

    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_cpimente_c_string_compare_left_greater_returns_greater_than_0\n"
                "returned a value greater than 0 when left string is lexicographically larger\n", length);
    }

    my_string_destroy(&hLeft_string);
    my_string_destroy(&hRight_string);

    return status;
}

Status test_cpimente_c_string_compare_left_smaller_returns_less_than_0(char* buffer, int length)
{
    MY_STRING hLeft_string = NULL;
    MY_STRING hRight_string = NULL;
    Status status;

    hLeft_string = my_string_init_c_string("app");
    hRight_string = my_string_init_c_string("apple");

    if (my_string_compare(hLeft_string, hRight_string) >= 0)
    {
        status = FAILURE;
        strncpy(buffer,"test_cpimente_c_string_compare_left_smaller_returns_less_than_0\n"
                "string compare did not a less than than 0\n", length);
    }

    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_cpimente_c_string_compare_left_smaller_returns_less_than_0\n"
                "returned a value less than 0 when left string is lexicographically smaller\n", length);
    }

    my_string_destroy(&hLeft_string);
    my_string_destroy(&hRight_string);

    return status;
}

Status test_cpimente_my_string_at_returns_valid_index(char* buffer, int length)
{
    MY_STRING hString = NULL;
    Status status;
    char *test = NULL;
    hString = my_string_init_default();
    my_string_push_back(hString, 'a');
    test = my_string_at(hString, 0);

    if(test == NULL)
    {
        status = FAILURE;
        strncpy(buffer, "test_cpimente_my_string_at_returns_valid_index\n",length);
    }

    else
    {
        strncpy(buffer, "test_cpimente_my_string_at_returns_valid_index\n"
                "my_string_at returned valid index of string\n", length);
        status = SUCCESS;
    }
    my_string_destroy(&hString);
    return status;
}

Status test_cpimente_my_string_at_invalid_index_returns_NULL(char* buffer, int length)
{
    MY_STRING hString = NULL;
    Status status;
    char *test;
    hString = my_string_init_default();
    test = my_string_at(hString, my_string_get_capacity(hString) + 1);

    if(test == NULL)
    {
        status = SUCCESS;
        strncpy(buffer, "test_cpimente_my_string_at_invalid_index_returns_NULL\n"
                "Successfully returned NULL when given an invalid index number\n",length);
    }

    else
    {
        strncpy(buffer, "test_cpimente_my_string_at_invalid_index_returns_NULL\n"
                "did not return NULL when given an invalid index number\n", length);
        status = FAILURE;
    }
    my_string_destroy(&hString);
    return status;
}

Status test_cpimente_popback_returns_failure_if_empty(char* buffer, int length)
{
    MY_STRING hString = NULL;
    Status status;
    Status ret;
    hString = my_string_init_default();
    ret = my_string_pop_back(hString);

    if (ret!= FAILURE)
    {
        strncpy(buffer, "test_cpimente_popback_returns_failure_if_empty\n"
                "pop_back operation did not return FAILURE when string is empty\n", length);
        status = FAILURE;
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_cpimente_popback_returns_failure_if_empty\n"
                "pop_back operation returned FAILURE when string is empty\n", length);
    }

    my_string_destroy(&hString);

    return status;
}

Status test_cpimente_c_string_NULL_terminated(char* buffer, int length)
{
    MY_STRING hString = NULL;
    Status status;
    int i;
    char* index;

    hString = my_string_init_default();

    for (i = 0; i < my_string_get_capacity(hString); i++)
    {
        my_string_push_back(hString, 'a');
    }
    my_string_c_str(hString);
    index = my_string_at(hString, my_string_get_capacity(hString));

    if (index != '\0')
    {
        status = FAILURE;
        strncpy(buffer,"test_cpimente_c_string_NULL_terminated\n"
                "string is not NULL terminated\n", length);
    }

    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_cpimente_c_string_NULL_terminated\n"
                "NULL terminator successfully added to string\n", length);
    }

    my_string_destroy(&hString);

    return status;
}

Status test_cpimente_init_c_string_returns_nonNULL(char* buffer, int length)
{
    MY_STRING hString = NULL;
    hString = my_string_init_c_string("test");
    if(hString == NULL)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_cpimente_init_c_string_returns_nonNULL\n" "init_c_string returns NULL", length);
        return FAILURE;
    }

    else
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_cpimente_init_c_string_returns_nonNULL\n"
                "init_c_string function did not return NULL\n", length);
        return SUCCESS;
    }

}

Status test_cpimente_string_insertion_returns_failure_given_empty_object(char* buffer, int length)
{
    MY_STRING hString = my_string_init_default();
    Status status;

    if (my_string_get_size(hString) <= 0)
    {
        status = SUCCESS;
        strncpy(buffer, "test_cpimente_string_insertion_returns_failure_given_empty_object\n"
                "string_insertion returned failure upon receiving empty string\n", length);
    }

    else
    {
        status = FAILURE;
        strncpy(buffer,"test_cpimente_string_insertion_returns_failure_given_empty_object\n"
                "string_insertion did not return failure upon receiving empty string\n", length);
    }

    my_string_destroy(&hString);

    return status;
}

Status test_cpimente_string_empty_returns_true_if_given_empty_string(char* buffer, int length)
{
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();
    if (my_string_empty(hString))
    {
        status = SUCCESS;
        strncpy(buffer, "test_cpimente_string_empty_returns_true_if_given_empty_string\n", length);
    }

    else
    {
        status = FAILURE;
        strncpy(buffer, "test_cpimente_string_empty_returns_true_if_given_empty_string\n"
                "my_string_empty did not return true when given an empty string\n", length);
    }

    my_string_destroy(&hString);
    return status;
}

Status test_cpimente_capacity_increase_after_pushback(char* buffer, int length)
{
    MY_STRING hString = NULL;
    Status status;
    int i;
    int capacity;
    hString = my_string_init_default();
    capacity = my_string_get_capacity(hString);
    
    for (i = 0; i < 300; i++)
    {
	my_string_push_back(hString, 'a');
    }

    if (my_string_get_capacity(hString) > capacity)
    {
        status = SUCCESS;
        strncpy(buffer, "test_cpimente_capacity_increase_after_pushback\n"
                "capacity has increased after push_back operation\n", length);
    }

    else
    {
        status = FAILURE;
        strncpy(buffer, "test_cpimente_size_increase_after_pushback\n"
                "expected an increase in capacity\n", length);
    }

    my_string_destroy(&hString);

    return status;

}

Status test_cpimente_capacity_unchanged_after_popback(char* buffer, int length)
{
    MY_STRING hString = NULL;
    Status status;
    int capacity;
    hString = my_string_init_default();
    capacity = my_string_get_capacity(hString);
    

    my_string_push_back(hString, 'a');
    my_string_pop_back(hString);

    if (my_string_get_capacity(hString) == capacity)
    {
        status = SUCCESS;
        strncpy(buffer, "test_cpimente_capacity_unchanged_after_popback\n"
                "capacity remains unchanged after pop_back operation\n", length);
    }

    else
    {
        status = FAILURE;
        strncpy(buffer, "test_cpimente_capacity_unchanged_after_popback\n"
                "expected capacity to remain unchanged\n", length);
    }

    my_string_destroy(&hString);

    return status;
}

Status test_cpimente_string_extraction_data_returns_nonNULL(char* buffer, int length)
{
    MY_STRING hString = NULL;
    FILE *fp;
    char *ch;
    fp = fopen("test.txt", "w");
    
    fprintf(fp, "%s", "test");
    fclose (fp);
    fp = fopen("test.txt", "r");
    hString = my_string_init_default();
    my_string_extraction(hString, fp);
   
    ch = my_string_at(hString, 0);

    if(ch == NULL)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_cpimente_string_extraction_data_returns_nonNULL\n" 
        "string_extraction returned NULL\n", length);
	fclose(fp);
        return FAILURE;
    }

    else
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_cpimente_string_extraction_data_returns_nonNULL\n"
                "string_extraction did not return NULL\n", length);
	fclose(fp);
        return SUCCESS;
    }
}

Status test_cpimente_string_extraction_get_size(char* buffer, int length)
{
    MY_STRING hString = NULL;
    FILE *fp;
    int size;
    fp = fopen("test2.txt", "w");
    
    fprintf(fp, "%s", "test2");
    fclose (fp);
    fp = fopen("test2.txt", "r");
    hString = my_string_init_default();
    my_string_extraction(hString, fp);
    size = my_string_get_size(hString);
   

    if(5 != size)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_cpimente_string_extraction_get_size\n" 
        "string_extraction did not extract string correctly\n", length);
	fclose(fp);
        return FAILURE;
    }

    else
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_cpimente_string_extraction_get_size\n"
                "returned correct size of expected string\n", length);
	fclose(fp);
        return SUCCESS;
    }
}

Status test_cpimente_string_extraction_return_failure_if_file_empty(char* buffer, int length)
{
    MY_STRING hString = NULL;
    FILE *fp;
    fp = fopen("test3.txt", "w+");
    hString = my_string_init_default();
    
 
    if(my_string_extraction(hString, fp) != FAILURE)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_cpimente_string_extraction_return_failure_if_file_empty\n" 
        "string_extraction did not return failure when extracting from empty file\n", length);
	fclose(fp);
        return FAILURE;
    }

    else
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_cpimente_string_extraction_return_failure_if_file_empty\n"
                "returned failure when extracting from empty file\n", length);
	fclose(fp);
        return SUCCESS;
    }
}
