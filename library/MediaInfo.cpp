//
// Created by 13918 on 2023/9/3.
//

#include "MediaInfo.h"

const QTime &MediaInfo::getDuration() const
{
    return duration;
}

void MediaInfo::setDuration(const QTime &duration)
{
    MediaInfo::duration = duration;
}

int MediaInfo::getVideoIdx() const
{
    return videoIdx;
}

void MediaInfo::setVideoIdx(int videoIdx)
{
    MediaInfo::videoIdx = videoIdx;
}

int MediaInfo::getAudioIdx() const
{
    return audioIdx;
}

void MediaInfo::setAudioIdx(int audioIdx)
{
    MediaInfo::audioIdx = audioIdx;
}

int MediaInfo::getSubtitleIdx() const
{
    return subtitleIdx;
}

void MediaInfo::setSubtitleIdx(int subtitleIdx)
{
    MediaInfo::subtitleIdx = subtitleIdx;
}
