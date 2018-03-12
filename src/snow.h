#ifndef __SNOW_H__
#define __SNOW_H__

#include <stdio.h>
#include <Flash++.h>

namespace com {
namespace ding {
class Snow
{
public:
    Snow(AS3::ui::flash::display::BitmapData bmd);
    ~Snow();

    float GetX();
    float GetY();
    void SetX(float value);
    void SetY(float value);

    void SetPosition(float x, float y);
    void SetScale(float value);
    void SetSpeed(float value);
    float GetSpeed();
    
    void RemoveSelf();
    void AddTo(AS3::ui::flash::display::DisplayObjectContainer parent);

private:
    AS3::ui::flash::display::Sprite mBody;
    float mSpeed;
};
} //ding
} //com

#endif