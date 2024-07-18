#include <gtest/gtest.h>
#include <cstdio>
#include <cassert>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <string>
#include <my_tests.hpp>


TEST(test, test01)
{
    int fd = open("GoogleTestLog.log", O_WRONLY|O_CREAT|O_TRUNC, 0660);
    assert(fd >= 0);
    int ret = dup2(fd, 1);
    assert(ret >= 0);
    std::cout << "\n\nStream has been redirected!\n" << std::endl;
    printf("test log on file01:\n");
    EXPECT_EQ(ft_test01(), EXIT_SUCCESS);
    printf("End of test01 \n\n\n");
    close(fd);
}