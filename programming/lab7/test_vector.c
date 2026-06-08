#include <stddef.h> 
#include <stdarg.h> 
#include <setjmp.h> 
#include <cmocka.h>
#include "vector.h"
static void test_vectorCreate_success(void **state)
{
    struct Vector *vec = vectorCreate();
    assert_non_null(vec);
    assert_int_equal(vec->size, 0);
    assert_int_equal(vec->capacity, 0);
    assert_null(vec->data);
}

static void test_vectorClean(void **state)
{
    struct Vector *vec = vectorCreate();
    vectorAppend(vec, 1);
    vectorClean(vec);
    assert_null(vec->data);
    assert_int_equal(vec->size, 0);
    assert_int_equal(vec->capacity, 0);
}

static void test_vectorAppend(void **state) 
{
    struct Vector* vec = vectorCreate();
    assert_true(vectorAppend(vec, 42)); 
    assert_int_equal(vec->size, 1);
    assert_int_equal(vec->data[0], 42);
}

static void test_vectorDelete(void **state) {
    struct Vector* vec = vectorCreate();
    vectorAppend(vec, 1); vectorAppend(vec, 2); vectorAppend(vec, 3);
    assert_true(vectorDelete(vec, 1)); 
    assert_int_equal(vec->size, 2);
    assert_int_equal(vec->data[0], 1);
    assert_int_equal(vec->data[1], 3);
}

static void test_binSearch_found(void **state) 
{
    int arr[] = {1, 3, 5, 7, 9};
    int index = binSearch(arr, 0, 4, 5);
    assert_int_equal(index, 2); 
}

static void test_selectSort(void **state) 
{
    int arr[] = {5, 3, 8, 1};
    selectSort(arr, 4);
    int expected[] = {1, 3, 5, 8};
    assert_memory_equal(arr, expected, 4 * sizeof(int));
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_vectorCreate_success),
        cmocka_unit_test(test_vectorClean),
        cmocka_unit_test(test_vectorAppend),
        cmocka_unit_test(test_vectorDelete),
        cmocka_unit_test(test_binSearch_found),
        cmocka_unit_test(test_selectSort)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
