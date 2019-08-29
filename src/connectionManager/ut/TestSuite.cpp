#include <gtest/gtest.h>
#include "MsgMerger.h"


TEST(MsgMergerTest, first) {
    MsgMerger merger;
    merger.addPart({5, 2, 1});
    EXPECT_FALSE(merger.isMsgReady());
    merger.addPart({1, 1});
    EXPECT_TRUE(merger.isMsgReady());
    Msg resultMsg = {5, 2, 1, 1, 1};
    EXPECT_EQ(merger.getMsg(), resultMsg);
}

TEST(MsgMergerTest, sec) {
    MsgMerger merger;
    merger.addPart({5, 2, 1});
    EXPECT_FALSE(merger.isMsgReady());
    merger.addPart({1, 1, 3, 1, 1});
    EXPECT_TRUE(merger.isMsgReady());
    Msg resultMsg = {5, 2, 1, 1, 1};
    EXPECT_EQ(merger.getMsg(), resultMsg);
    Msg resultMsg2 = {3, 1, 1};
    EXPECT_EQ(merger.getMsg(), resultMsg2);
}