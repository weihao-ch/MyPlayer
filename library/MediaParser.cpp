//
// Created by 13918 on 2023/9/3.
//

#include "MediaParser.h"
#include "def.h"

MediaParser::MediaParser(AVFormatContext *ctx, MediaInfo *info, AVCodecContext *videoDecCtx, AVCodecContext *audioDecCtx)
        : fmtCtx(ctx), mediaInfo(info), videoDecCtx(videoDecCtx), audioDecCtx(audioDecCtx)
{

}

void MediaParser::parse(const QString &filePath)
{
    int rc = 0;
    std::string stdStr = filePath.toStdString();
    const char *cFilePath = stdStr.c_str();
    rc = avformat_open_input(&fmtCtx, cFilePath, nullptr, nullptr);
    if (FF_ERROR(rc)) {
        return;
    }

    rc = avformat_find_stream_info(fmtCtx, nullptr);
    if (FF_ERROR(rc)) {
        return;
    }

    int vIdx = openCodecContext(&videoDecCtx, AVMEDIA_TYPE_VIDEO);
    mediaInfo->setVideoIdx(vIdx);

    int aIdx = openCodecContext(&audioDecCtx, AVMEDIA_TYPE_AUDIO);
    mediaInfo->setAudioIdx(aIdx);
}

int MediaParser::openCodecContext(AVCodecContext **decCtx, enum AVMediaType type)
{
    int rc = 0;
    int streamIdx = -1;
    AVStream *st = nullptr;
    const AVCodec *dec = nullptr;

    streamIdx = av_find_best_stream(fmtCtx, type, -1, -1, nullptr, 0);
    if (streamIdx < 0) {
        return -1;
    }

    st = fmtCtx->streams[streamIdx];
    dec = avcodec_find_decoder(st->codecpar->codec_id);
    if (dec == nullptr) {
        //todo 解码器未找到错误处理
    }

    *decCtx = avcodec_alloc_context3(dec);
    if (*decCtx == nullptr) {
        //todo 错误处理
    }

    rc = avcodec_parameters_to_context(*decCtx, st->codecpar);
    if (FF_ERROR(rc)) {
        // todo 错误处理，复制参数到decCtx
    }

    rc = avcodec_open2(*decCtx, dec, nullptr);
    if (FF_ERROR(rc)) {
        // todo 错误处理
    }

    return streamIdx;
}
