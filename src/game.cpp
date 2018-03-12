#include "game.h"

using namespace AS3::ui;
using namespace com::ding;

Game::Game()
{
    InitStage();
    InitLayer();
    InitImage();
    InitLoops();
}

Game::~Game()
{
    while (mSnowArr.size() > 0)
        RemoveSnowByIndex(0);
    mSnowArr.clear();
}

void Game::InitStage()
{
    srand((unsigned)time(NULL));

    mStage = internal::get_Stage();
    mStage->scaleMode = flash::display::StageScaleMode::NO_SCALE;
    mStage->align = flash::display::StageAlign::TOP_LEFT;
    mStage->frameRate = 60;
    mStage->color = 0x000000;
}

void Game::InitLayer()
{
    mLayer = flash::display::Sprite::_new();
    mStage->addChild(mLayer);
}

void Game::InitImage()
{
    mSnowBmd = flash::display::BitmapData::_new(
        10, 10, true, 0x00000000);

    flash::net::URLRequest url;
    url = flash::net::URLRequest::_new();
    url->url = "image/123.png";

    flash::display::Loader loader;
    flash::display::LoaderInfo info;
    loader = flash::display::Loader::_new();
    info = loader-> contentLoaderInfo;
    info->addEventListener(
        flash::events::Event::COMPLETE, 
        Function::_new(onLoadComplete, this));
    loader->load(url);
}

void Game::InitSnows()
{
    float x, y;
    for (int i = 0; i < 50; i++)
    {
        x = rand() % mStage->stageWidth;
        y = rand() % mStage->stageHeight;
        CreateSnow(x, y);
    }
}

void Game::InitLoops()
{
    mStage->addEventListener(
        flash::events::Event::ENTER_FRAME, 
        Function::_new(onEnterFrame, this));
}

void Game::CreateSnow(float x, float y)
{
    float scale = (rand() % 30 + 20) / 100.0f;
    float speed = (rand() % 50 + 50) / 100.0f;

    Snow* snow = new Snow(mSnowBmd);
    snow->SetScale(scale);
    snow->SetSpeed(speed);
    snow->SetPosition(x, y);
    snow->AddTo(mLayer);
    mSnowArr.push_back(snow);
}

void Game::MoveSnows()
{
    Snow* snow;
    float y, speed;

    int len = mSnowArr.size();
    for (int i = 0; i < len; i++)
    {
        snow = mSnowArr[i];
        speed = snow->GetSpeed();
        y = snow->GetY();
        snow->SetY(y + speed);
    }
}

void Game::CheckTime()
{
    mTimeCount++;
    if (mTimeCount >= 10)
    {
        mTimeCount = 0;

        float x = rand() % mStage->stageWidth;
        CreateSnow(x, -40);
    }
}

void Game::CheckSnow()
{
    Snow* snow;

    for (int i = 0; i < mSnowArr.size(); i++)
    {
        snow = mSnowArr[i];
        if (snow->GetY() > mStage->stageHeight + 40)
        {
            RemoveSnowByIndex(i);
            i--;
        }
    }
}

void Game::RemoveSnowByIndex(int index)
{
    if (index >= 0 && index < mSnowArr.size())
    {
        Snow* snow = mSnowArr[index];
        mSnowArr.erase(mSnowArr.begin() + index);
        snow->RemoveSelf();
        delete snow;
    }
}

var Game::onEnterFrame(void *arg, var as3Args)
{
    Game* game = (Game*) arg;

    game->CheckTime();
    game->MoveSnows();
    game->CheckSnow();

    return internal::_undefined;
}

var Game::onLoadComplete(void *arg, var as3Args)
{
    flash::events::Event e;
    e = (flash::events::Event) as3Args[0];

    flash::display::LoaderInfo info;
    info = (flash::display::LoaderInfo) e->target;

    flash::display::Bitmap bmp;
    bmp = (flash::display::Bitmap) info->content;

    Game* game = (Game*) arg;
    game->mSnowBmd = bmp->bitmapData;

    game->InitSnows();
    
    return internal::_undefined;
}