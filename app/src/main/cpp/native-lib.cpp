#include <jni.h>
#include <string>


// 实现全屏
/*
 * 为什么要用 extern "C"呢？
 * 因为我们的源码文件是C++ 而C++的编译器会把我们的函数名进行签名会导致我们的JAVA程序无法正常的找到正确的函数
 * */
extern "C"
void
Java_com_example_administrator_ndkdemo_MainActivity_fullScreenJNI(JNIEnv *env, jobject instance,
                                                                  jobject window) {
    // TODO
    jclass native_window = env->GetObjectClass(window); // 获取window对象的C++表示 有点类似于Java的反射机制
    jmethodID setFlags = env->GetMethodID(native_window, "setFlags", "(II)V");
    //0x00000400
    env->CallVoidMethod(window,setFlags,0x00000400,0x00000400);
}

extern "C"
jstring
Java_com_example_administrator_ndkdemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
