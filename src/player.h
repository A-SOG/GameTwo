#pragma once
#include"core/Actor.h"
#include "affilicate/sprite_anim.h"
class Player :public Actor
{
private:
    SpriteAnim* sprite_idle_ = nullptr;//静止动画
    SpriteAnim* sprite_move_ = nullptr;//移动
    bool is_moving_ = false;
public:
	virtual void init() override;
    virtual void handleEvents(SDL_Event& event) override;
    virtual void update(float dt) override;
    virtual void render() override;
    virtual void clean() override;


    void keyboardControl();
    void syncCamera();
    void checkState();//检查并更新状态
    void changeState(bool is_moving);//根据状态切换动画）
};