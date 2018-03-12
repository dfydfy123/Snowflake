#ifndef __GAME_H__
#define __GAME_H__

#include <vector>
#include <stdio.h>
#include <Flash++.h>
#include "snow.h"

namespace com {
namespace ding {
class Game
{
public:
    Game();
    ~Game();

private:
    AS3::ui::flash::display::Stage mStage;
    AS3::ui::flash::display::Sprite mLayer;
    AS3::ui::flash::display::BitmapData mSnowBmd;
    std::vector<com::ding::Snow*> mSnowArr;
    int mTimeCount;

    void InitStage();
    void InitLayer();
    void InitImage();
    void InitSnows();
    void InitLoops();
    void MoveSnows();
    void CheckTime();
    void CheckSnow();
    void CreateSnow(float x, float y);
    void RemoveSnowByIndex(int index);

    static AS3::ui::var onEnterFrame(void *arg, AS3::ui::var as3Args);
    static AS3::ui::var onLoadComplete(void *arg, AS3::ui::var as3Args);
};
} //ding
} //com

#endif