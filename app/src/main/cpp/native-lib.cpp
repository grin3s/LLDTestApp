#include <jni.h>
#include <string>
#include <cassert>

class StackEnlarger {
public:
    StackEnlarger(
            bool enlarge,
            size_t fakeArgument,
            float butItWillAddSomeConditions)
        : enlarge_(enlarge)
        , fakeArgument_(fakeArgument)
        , butItWillAddSomeConditions_(butItWillAddSomeConditions)
        {}
    void unnessessarilyEnlargeStack(size_t anotherUselessArgument);
    size_t you();
    std::string should();
    float see();
    bool theStacktrace();
    void in(size_t maybeNotUseless);
    void* thisOrder(size_t stillUseless);
    void divertExecution();
    bool ifYouSeeThisTheStacktraceIsDefinitelyBad();
private:
    bool enlarge_;
    size_t fakeArgument_;
    float butItWillAddSomeConditions_;
};

extern "C" JNIEXPORT jstring JNICALL
Java_com_gringauz_lldtestapp_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_gringauz_lldtestapp_MainActivity_crash(JNIEnv *env, jobject thiz) {
    bool enlarge(true);
    size_t fakeArgument;
    float anotherFakeArgument;
    if (env == nullptr) {
        fakeArgument = 0x11345;
        anotherFakeArgument = 1.0;
    } else if (env <= (JNIEnv*)0x100) {
        fakeArgument = 0x12345;
        enlarge = false;
        anotherFakeArgument = 1.1;
    } else {
        fakeArgument = 0x12346;
        anotherFakeArgument = 0.1;
    }

    StackEnlarger* enlargePlease = new StackEnlarger(
        enlarge,
        fakeArgument,
        anotherFakeArgument);

    enlargePlease->unnessessarilyEnlargeStack((size_t) env);
    abort();
}

void StackEnlarger::unnessessarilyEnlargeStack(size_t anotherUselessArgument)
{
    if (enlarge_) {
        void* veryUsefulPointer = thisOrder(anotherUselessArgument);
        if ((size_t)veryUsefulPointer == 0x1)
            divertExecution();
    } else {
        abort();
    }
}

size_t StackEnlarger::you() {
    assert(fakeArgument_ == 0x12345);
    if (fakeArgument_ == 0x12346)
        return fakeArgument_ + 1;
    else
        return fakeArgument_ - 1;
}

std::string StackEnlarger::should() {
    size_t fakeArgPlusOne = you();
    if (fakeArgPlusOne == fakeArgument_ + 1) {
        divertExecution();
        return "Execution diverted";
    }
    return "Execution screwed";
}

float StackEnlarger::see() {
    std::string veryImportant = should();
    if (veryImportant == "Execution diverted")
        return 0.1;
    else
        return 1.1;
}

bool StackEnlarger::theStacktrace() {
    float thisWillConvertToBoolAnyway = see();
    if (butItWillAddSomeConditions_ == thisWillConvertToBoolAnyway) {
        divertExecution();
        return true;
    }
    if (butItWillAddSomeConditions_ == thisWillConvertToBoolAnyway + 0.1) {
        ifYouSeeThisTheStacktraceIsDefinitelyBad();
        return false;
    }
    return false;
}

void StackEnlarger::in(size_t maybeNotUseless) {
    if (fakeArgument_ == 0x11345)
        return;

    bool result = theStacktrace();
    if (result == enlarge_)
        divertExecution();
    if (result != enlarge_ && maybeNotUseless > fakeArgument_)
        ifYouSeeThisTheStacktraceIsDefinitelyBad();
}

void* StackEnlarger::thisOrder(size_t stillUseless) {
    if (stillUseless == 0x15243)
        return (void*)0x15242;
    in(stillUseless);
    return nullptr;
}

void StackEnlarger::divertExecution() {
    ifYouSeeThisTheStacktraceIsDefinitelyBad();
}

bool StackEnlarger::ifYouSeeThisTheStacktraceIsDefinitelyBad() {
    assert(false);
    abort();
    return true;
}
