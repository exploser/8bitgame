#pragma once
#include "Drawable.hpp"
#include "Scene.hpp"
#include "IdGenerator.hpp"

namespace engine::scene
{
class DrawableNode :
	public INode
{
    const uint16_t id = utils::NextId();
    Color color;
    Vector2<int16_t> position;

    utils::SharedPtr<Drawable> geometry;
	std::list<utils::SharedPtr<INode>> children;

public:
	DrawableNode(const utils::SharedPtr<Drawable> &geometry, Color color);
	DrawableNode(const utils::SharedPtr<Drawable> &geometry, const Vector2<int16_t> &position, Color color);
	virtual uint16_t GetID() const override;
	virtual Vector2<int16_t> GetPosition() const override;

	virtual void SetPosition(const Vector2<int16_t> &position) override;
	virtual void Draw(utils::SharedPtr<IScreen> &screen) override;
};
}
