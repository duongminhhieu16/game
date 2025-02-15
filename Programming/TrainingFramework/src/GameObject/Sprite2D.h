#pragma once
#include "baseobject.h"
#include <memory>

class Sprite2D : public BaseObject
{
private:
	std::string		m_Text;
	Vector2			m_Vec2DPos;
	GLint			m_iHeight;
	GLint			m_iWidth;

	void			CaculateWorldMatrix();

public:
	Sprite2D(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture);
	Sprite2D(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, Vector4 color);
	~Sprite2D();

	void		Init() override;
	void		Draw() override;
	void		Update(GLfloat deltatime) override;

	void		SetText(std::string text);
	std::string	GetText();

	void		Set2DPosition(GLfloat x, GLfloat y);
	void		Set2DPosition(Vector2 pos);

	Vector2		Get2DPosition();
	void		SetSize(GLint width, GLint height);

};

