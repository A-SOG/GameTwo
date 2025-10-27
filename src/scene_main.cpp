#include "scene_main.h"
#include"player.h"
#include "enemy.h"
#include "world/effect.h"
#include "screen/ui_mouse.h"
#include "world/spell.h"
void SceneMain::init()
{
	//初始化世界大小
	SDL_HideCursor();
	world_size_ = game_.getScreenSize() * 3.0f;
	camera_position_ = world_size_ / 2.0f - game_.getScreenSize() / 2.0f;
	player_ = new Player();
	player_->init();
	player_->setPosition(world_size_ / 2.0f);
	addChild(player_);
	ui_mouse_ = UIMouse::addUIMouseChild(this, "assect/UI/29.png", "assets/UI/30.png", 1.0f, Anchor::CENTER);

	auto enemy = new Enemy();
	enemy->init();
	enemy->set_target(player_);
	enemy->setPosition(world_size_ / 2.0f + glm::vec2(200.0f));
	addChild(enemy);
	Effect::addEffectChild(this, "assect/effect/184_3.png", world_size_ / 2.0f + glm::vec2(200.0f), 1.0f, enemy);

}

void SceneMain::handleEvents(SDL_Event& event)
{
	Scene::handleEvents(event);
}

void SceneMain::update(float dt)
{
	Scene::update(dt);
}

void SceneMain::renderBackground()
{//计算世界左上角和右下角在屏幕上的坐标
	auto start = -camera_position_;
	auto end = world_size_ - camera_position_;
	game_.drawGrid(start, end, 80.0f, { 0.5,0.5,0.5,1.0 });
	game_.drawBoundary(start, end, 5.0f, { 1.0, 1.0, 1.0, 1.0 });
}

void SceneMain::render()
{
	renderBackground();
	Scene::render();
	
	
}

void SceneMain::clean() {
	Scene::clean();

}