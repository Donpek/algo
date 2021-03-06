#ifndef ALGO_H
#define ALGO_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <sys/time.h>

#define internal static
#define local_persist static
#define global_variable static

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef long long i64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef unsigned long u64;
typedef u32 b32;

#define KILOBYTE 1024

internal i64
RangeI64(i64 Min, i64 Max)
// NOTE(gunce): min and max are inclusive.
{
    return (rand() % (Max - Min + 1)) + Min;
}

typedef struct list_node_t
{
    struct list_node_t *Next;
    i64 Value;
} list_node;

typedef struct doubly_linked_list_note_t
{
  struct doubly_linked_list_note_t *Prev;
  i64 Data;
  struct doubly_linked_list_note_t *Next;
} double_list_node;

#include "queue.c"
#include "stack.c"
#include "linked_list_stack.c"
#include "list_bst.c"
#include "data_structures_test.c"
#include "sorting.c"
#include "algorithms_test.c"
#endif
