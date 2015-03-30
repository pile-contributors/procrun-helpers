#include <gtest/gtest.h>
#include <procrun/procrun.h>
#include <QApplication>

#include <procrun/procrun.h>

class TestUsage : public ::testing::Test {
    QApplication * app;
public:

    TestUsage () {}

    virtual ~TestUsage () {}

    void SetUp(){

        int argc = 1;
        char *argv[] = {strdup("test")};
        app = new  QApplication(argc, argv);
    }
    void TearDown(){
        delete app;
    }

};

TEST_F(TestUsage, initial_state) {
    ProcRun pr;
    QStringList arguments;
    QStringList prog_input;

    pr.setProgram ("ls");
    pr.setArguments (arguments);
    pr.perform (prog_input);

    //EXPECT_TRUE(pr.runDuration() > 0);
    //EXPECT_TRUE(pr.durationInSeconds() > 0);
    //EXPECT_TRUE(pr.durationInMiliSeconds() > 0);
    EXPECT_TRUE(pr.std_err_output_.count() == 0);
    EXPECT_TRUE(pr.std_out_output_.count() > 0);
    EXPECT_TRUE(pr.all_output_ == pr.std_out_output_);
    EXPECT_TRUE(pr.b_started_);
    EXPECT_TRUE(pr.errors_.count() == 0);
    EXPECT_TRUE(pr.states_.count() > 0);
}

