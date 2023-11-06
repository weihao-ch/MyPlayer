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