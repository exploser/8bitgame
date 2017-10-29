#pragma once
#include <map>

#include "SharedPtr.hpp"
#include "Vector2.hpp"
#include "IScreen.hpp"

namespace engine::scene
{
struct INode
{
	virtual ~INode()
	{
	}

	virtual uint16_t GetID() const = 0;
	virtual Vector2<int16_t> GetPosition() const = 0;

	virtual void SetPosition(const Vector2<int16_t> &position) = 0;
	virtual void Draw(utils::SharedPtr<IScreen> &screen) = 0;
};

class Scene
{
	using NodePtr = utils::SharedPtr<INode>;

	std::map<uint16_t, NodePtr> nodes;

public:
	void AddNode(NodePtr node);

	void AddNode(const utils::SharedPtr<Drawable> &geometry, const Vector2<int16_t> &position);

	void RemoveNode(int id);

	void RemoveNode(const NodePtr &node);

	NodePtr GetNode(int id) const;

	void Draw(utils::SharedPtr<IScreen> screen);
};
}
