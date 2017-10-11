//
// Created by zhaopf on 2017/10/9.
//

#ifndef AVSYNCHRONIZATION_FFMPEGAUDIO_H
#define AVSYNCHRONIZATION_FFMPEGAUDIO_H

#include <queue>
#include <SLES/OpenSLES_Android.h>

extern "C" {
#include <pthread.h>
#include "Log.h"
#include <libavcodec/avcodec.h>
#include <libswresample/swresample.h>

class FFmpegAudio {
public:
    FFmpegAudio();

    ~FFmpegAudio();

    void setAvCodecContext(AVCodecContext *codecContext);

    int get(AVPacket *packet);

    int put(AVPacket *packet);

    int createPlayer();

    void play();

    void stop();

public:
    //是否正在播放
    int isPlay;
    //流索引
    int index;
    //音频队列
    std::queue<AVPacket *> queue;
    //处理线程
    pthread_t p_playid;
    //解码器上下文
    AVCodecContext *pCodecCtx;
    //同步锁
    pthread_mutex_t mutex;
    //条件变量
    pthread_cond_t cond;

    SwrContext *swrContext;
    uint8_t *out_buffer;
    int out_channel_nb;
    //相对于第一帧时间
    double clock;

    AVRational time_base;

    SLObjectItf engineObject;
    SLEngineItf engineEngine;
    SLEnvironmentalReverbItf outputMixEnvironmentalReverb;
    SLObjectItf outputMixObject;
    SLObjectItf bgPlayerObject;
    SLEffectSendItf bgPlayerEffectSend;
    SLVolumeItf bgPlayerVolume;
    SLPlayItf bgPlayerPlay;
    SLAndroidSimpleBufferQueueItf bgPlayerBufferQueue;
};
};

#endif //AVSYNCHRONIZATION_FFMPEGAUDIO_H