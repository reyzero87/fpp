#pragma once

#include "OutputProcessor.h"

class ReyTestOutputProcessor : public OutputProcessor {
public:
    ReyTestOutputProcessor(const Json::Value& config);
    ReyTestOutputProcessor(int src, int dst, int count, int loop, int reverse);
    virtual ~ReyTestOutputProcessor();

    virtual void ProcessData(unsigned char* channelData) const override;

    virtual OutputProcessorType getType() const override { return REYTEST; }

    int getSourceChannel() const { return sourceChannel; }
    int getDestChannel() const { return destChannel; }
    int getCount() const { return count; }
    int getLoops() const { return loops; }
    int getReverse() const { return reverse; }

    virtual void GetRequiredChannelRanges(const std::function<void(int, int)>& addRange) override;

protected:
    int sourceChannel;
    int destChannel;
    int count;
    int loops;
    int reverse;
};
