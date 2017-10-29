#pragma once
#include "IScreen.hpp"
#include "SharedPtr.hpp"

namespace engine::SDL
{
class MockupScreen :
	public IScreen
{
	friend class utils::SharedPtr<MockupScreen>;

	MockupScreen();
	virtual ~MockupScreen();

public:
	static utils::SharedPtr<MockupScreen> GetInstance();
	virtual void Draw(int16_t x, int16_t y, Color color) override;
	virtual void Draw(const Drawable &dr, int16_t x, int16_t y, Color color) override;
	virtual void Render() override;
	virtual void Clear(Color color) override;
};
}
