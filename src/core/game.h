#pragma once
#include<SDL3/SDL.h>
#include<SDL3_image/SDL_image.h>
#include<SDL_mixer.h>
#include<glm/glm.hpp>
#include<string>
#include "asset_store.h" 
#include <SDL3_ttf/SDL_ttf.h>
#include<random>
struct Texture;
class Scene;//向前声明


class Game {

	AssetStore* asset_store_ = nullptr; // 资源管理器
	glm::vec2 screen_size_ = glm::vec2(0);//屏幕大小
	glm::vec2 mouse_position_ = glm::vec2(0);
	SDL_MouseButtonFlags mouse_buttons_ = 0;

	bool is_running_ = true;//是否运行
	Scene* current_scene_ = nullptr;//当前场景

	SDL_Window * window_ = nullptr;//窗口
	SDL_Renderer* renderer_ = nullptr;//渲染
	TTF_TextEngine* ttf_engine_ = nullptr;
	std::mt19937 gen_ = std::mt19937(std::random_device{}());
	//私有构造函数

	Uint64 FPS_ = 60;//fps
	Uint64 frame_delay_ = 0;//帧延长，单位ns
	float dt_ = 0.0f;//帧间隔

	int score_ = 0;
	int high_score_ = 0;
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

	glm::vec2 getMousePosition() const { return mouse_position_; } // 获取鼠标位置
	SDL_MouseButtonFlags getMouseButtons() const { return mouse_buttons_; } // 获取鼠标按钮
	//渲染
   // 获取分数
	void setScore(int score);
	int getScore() const { return score_; } 
	// 设置最高分
	void setHighScore(int high_score) { high_score_ = high_score; }
	// 获取最高分
	int getHighScore() const { return high_score_; } 
	void addScore(int score);
	void renderTexture(const Texture& texture, const glm::vec2& position, const glm::vec2& size,const glm::vec2&mask=glm::vec2(1.0f));// 渲染纹理

	//渲染圆形纹理
	void renderFillCircle(const glm::vec2& position, const glm::vec2 size, float alpha);

	//渲染能量条
	void renderHBar(const glm::vec2& position, const glm::vec2& size, float percent, SDL_FColor color);

	//工具函数
	void drawGrid(const glm::vec2& top_left, const glm::vec2& botton_right, float grid_width, SDL_FColor fcolor); // 绘制网格
	void drawBoundary(const glm::vec2& top_left, const glm::vec2& botton_right, float boundary_width, SDL_FColor fcolor); // 绘制边界
	// 文字函数
	TTF_Text* createTTF_Text(const std::string& text, const std::string& font_path, int font_size = 16);
	//随机数生成

	float randomFloat(float min,float max)
	{
		return std::uniform_real_distribution<float>(min, max)(gen_);
	}
	int randomInt(int min,int max)
	{
		return std::uniform_int_distribution<int>(min, max)(gen_);
	}
	glm::vec2 randomVec2(const glm::vec2& min, const glm::vec2& max)
	{
		return glm::vec2(randomFloat(min.x, max.x), randomFloat(min.y, max.y));
	}

	glm::ivec2 randomIVec2(const glm::ivec2& min, const glm::ivec2& max) 
	{ return glm::ivec2(randomInt(min.x, max.x), randomInt(min.y, max.y)); }
};
