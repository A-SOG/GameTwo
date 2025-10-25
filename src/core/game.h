#pragma once
#include<SDL3/SDL.h>
#include<SDL3_image/SDL_image.h>
#include<SDL_mixer.h>
#include<glm/glm.hpp>
#include<string>
#include "asset_store.h" 
#include <SDL3_ttf/SDL_ttf.h>
struct Texture;
class Scene;//向前声明


class Game {

	AssetStore* asset_store_ = nullptr; // 资源管理器
	glm::vec2 screen_size_ = glm::vec2(0);//屏幕大小
	bool is_running_ = true;//是否运行
	Scene* current_scene_ = nullptr;//当前场景

	SDL_Window * window_ = nullptr;//窗口
	SDL_Renderer* renderer_ = nullptr;//渲染

	
	//私有构造函数

	Uint64 FPS_ = 60;//fps
	Uint64 frame_delay_ = 0;//帧延长，单位ns
	float dt_ = 0.0f;//帧间隔
	Game() {}

	//禁止拷贝构造函数与赋值操作符

	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;




public:


	static Game& GetInstance() {

		static Game instance;
		return instance;
	}


	void run();
	void init(std::string title,int width,int height);//初始化游戏
	void handleEvents();//处理事件
	void update(float dt);//跟新游戏状态
	void render();
	void clean();

	//获取数据
	glm::vec2 getScreenSize()const { return screen_size_; }//屏幕大小
	Scene* getCurrentScene()const { return current_scene_; }//获取当前场景
	AssetStore* getAssetStore() const { return asset_store_; } // 获取资源管理器

	//渲染
	void renderTexture(const Texture& texture, const glm::vec2& position, const glm::vec2& size);// 渲染纹理

	//渲染圆形纹理
	void renderFillCircle(const glm::vec2& position, const glm::vec2 size, float alpha);

	//工具函数
	void drawGrid(const glm::vec2& top_left, const glm::vec2& botton_right, float grid_width, SDL_FColor fcolor); // 绘制网格
	void drawBoundary(const glm::vec2& top_left, const glm::vec2& botton_right, float boundary_width, SDL_FColor fcolor); // 绘制边界


};
