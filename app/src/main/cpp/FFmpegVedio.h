//
// Created by zhaopf on 2017/10/9.
//

#ifndef AVSYNCHRONIZATION_FFMPEGVEDIO_H
#define AVSYNCHRONIZATION_FFMPEGVEDIO_H

#include <queue>
#include "FFmpegAudio.h"

extern "C" {
#include <unistd.h>
#include <pthread.h>
#include <libswscale/swscale.h>
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavutil/imgutils.h>
#include <libavutil/time.h>
#include "Log.h"

class FFmpegVedio {
public:
    FFmpegVedio();

    ~FFmpegVedio();

    int put(AVPacket *packet);

    int get(AVPacket *packet);

    void play();

    void stop();

    void setAvCodecContext(AVCodecContext *codecContext);

    /**
     * 设置回调接口
     * @param call
     */
    void setPlayCall(void (*call)(AVFrame *frame));

    double synchronize(AVFrame *frame, double play);

    void setAudio(FFmpegAudio *audio);

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

    FFmpegAudio *audio;
    AVRational time_base;
    double clock;
};
};
#endif //AVSYNCHRONIZATION_FFMPEGVEDIO_H