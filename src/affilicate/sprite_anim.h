#pragma once
#include"sprite.h"

class SpriteAnim :public Sprite
{
	int current_frame_ = 0;
	int total_frame_ = 0;
	int fps_ = 10;
	int frame_timer_ = 0.0f;

	bool is_loop_ = true;
public:
	static SpriteAnim* addSpriteAnimChild(ObjectScreen* parent, const std::string& file_path, float scale = 1.0f);
	virtual void update(float dt)override;
	virtual void setTexture(const Texture& texture)override;
	

	int getCurrentFrame()const { return current_frame_; }
	void setCurrentFrame(int curren_frame) { current_frame_ = curren_frame; }
	int getTotalFrame()const { return total_frame_; }
	void setTotalFrame(int total_frame) { total_frame_ = total_frame; }

	int getFps() { return fps_; }
	void setFps(int fps) { fps_ = fps; }


	float getFrameTimer() const { return frame_timer_; }
	void setFrameTimer(float frame_timer) { frame_timer_ = frame_timer; }
	bool getLoop() const { return is_loop_; }
	void setLoop(bool is_loop) { is_loop_ = is_loop; }


};



