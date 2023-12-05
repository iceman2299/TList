#include "Tlistnode.h"



#include <gtest.h>

TEST(Stack, can_create_Stack_with_positive_length)
{
    ASSERT_NO_THROW(TStack<int> q(3));
}


TEST(Stack, can_get_count)
{
    TStack<int> q(3);

    EXPECT_EQ(0, q.GetCount());
}

TEST(Stack, can_create_copy)
{
    TStack<int> q(4);

    ASSERT_NO_THROW(TStack<int> cop = q);
}

TEST(Stack, can_push)
{
    TStack<int> q(3);
    int addelem = 5;
    q.Push(addelem);
    EXPECT_EQ(1, q.GetCount());
}

TEST(Stack, can_pull)
{
    TStack<int> q(3);
    int addelem = 5;
    q.Push(addelem);
    q.Pull();
    EXPECT_EQ(1, q.IsEmpty());
}
