#include "snow.h"

using namespace AS3::ui;
using namespace com::ding;

Snow::Snow(flash::display::BitmapData bmd)
{
    flash::display::Bitmap bmp;
    
    mBody = flash::display::Sprite::_new();
    bmp = flash::display::Bitmap::_new(bmd, "auto", true);

    bmp->x = -bmp->width / 2;
    bmp->y = -bmp->height / 2;

    mBody->addChild(bmp);

    mSpeed = 1;
}

Snow::~Snow()
{

}

float Snow::GetX()
{
    return mBody->x;
}

float Snow::GetY()
{
    return mBody->y;
}

void Snow::SetX(float value)
{
    mBody->x = value;
}

void Snow::SetY(float value)
{
    mBody->y = value;
}

void Snow::SetPosition(float x, float y)
{
    mBody->x = x;
    mBody->y = y;
}

void Snow::SetScale(float value)
{
    mBody->scaleX = value;
    mBody->scaleY = value;
}

void Snow::SetSpeed(float value)
{
    mSpeed = value;
}

float Snow::GetSpeed()
{
    return mSpeed;
}

void Snow::AddTo(flash::display::DisplayObjectContainer parent)
{
    if (parent != internal::_null)
        parent->addChild(mBody);
}

void Snow::RemoveSelf()
{
    flash::display::DisplayObjectContainer parent;
    parent = mBody->parent;
    
    if (parent != internal::_null)
        parent->removeChild(mBody);
}