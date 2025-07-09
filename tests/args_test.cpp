#include <deep-zoom/args.h>

#include <gtest/gtest.h>

#include <array>

TEST(TestArgs, emptyForZeroCount)
{
    const char *argv[]{"ooops"};

    std::vector<std::string_view> args = zoomer::args(0, argv);

    ASSERT_TRUE(args.empty());
}

TEST(TestArgs, countMatches)
{
    const char *argv[]{"program-name", "arg1", "arg2"};

    std::vector<std::string_view> args = zoomer::args(std::size(argv), argv);

    ASSERT_FALSE(args.empty());
    ASSERT_EQ(std::size(argv), args.size());
}

TEST(TestArgs, valuesMatch)
{
    const char *argv[]{"program-name", "arg1", "arg2"};

    std::vector<std::string_view> args = zoomer::args(std::size(argv), argv);

    ASSERT_EQ(args.size(), 3);
    EXPECT_EQ(argv[0], args[0]);
    EXPECT_EQ(argv[1], args[1]);
    EXPECT_EQ(argv[2], args[2]);
}
