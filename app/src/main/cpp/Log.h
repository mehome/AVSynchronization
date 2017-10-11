//
// Created by zhaopf on 2017/10/9.
//

#ifndef AVSYNCHRONIZATION_LOG_H
#define AVSYNCHRONIZATION_LOG_H

#include <android/log.h>

#define LOG_TAG "pf"

#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#endif //AVSYNCHRONIZATION_LOG_H
