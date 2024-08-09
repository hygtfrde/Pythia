#include <common_header.hpp>
#include <test_declarations.hpp>

// TEST(test, test00)
// {
//     int fd = open("GoogleTestLog.log", O_WRONLY|O_CREAT|O_TRUNC, 0660);
//     assert(fd >= 0);
//     int ret = dup2(fd, 1);
//     assert(ret >= 0);
//     std::cout << "\n\nStream has been redirected!\n" << std::endl;
//     printf("test log on file01:\n");
//     EXPECT_EQ(ft_test01(), EXIT_SUCCESS);
//     printf("End of test01 \n\n\n");
//     close(fd);
// }


TEST(test, Test01)
{
    ASSERT_EQ(1, 1);
}

TEST(test, Test02)
{
    ASSERT_TRUE(true);
}

namespace MyTests
{
    void run_tests()
    {
        int argc = 1;
        char* argv[1] = { (char*)"main" };
        ::testing::InitGoogleTest(&argc, argv);
        RUN_ALL_TESTS();
    }
}