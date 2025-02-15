#include "Application.h"
#include "Shaders.h"
#include "Texture.h"
#include "Models.h"
#include "Camera.h"
#include <memory>
extern GLint screenWidth;
extern GLint screenHeight;

Application::Application(void)
{
}


Application::~Application(void)
{
}


void Application::Init()
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	std::shared_ptr<Shaders> m_Shaders = std::make_shared<Shaders>();
	std::shared_ptr<Shaders> shade;

	std::shared_ptr<Texture> m_texture = std::make_shared<Texture>();
	std::shared_ptr<Texture> texture;

	std::shared_ptr<Models> m_model = std::make_shared<Models>();
	std::shared_ptr<Models> model;

	std::shared_ptr<Camera> m_Camera = std::make_shared<Camera>();
	std::shared_ptr<Camera> camera;

	//button
	m_Shaders = std::make_shared<Shaders>();
	m_Shaders->Init("..\\Data\\Shaders\\TextureShader.vs", "..\\Data\\Shaders\\TextureShader.fs");
	shade = std::make_shared<Shaders>();

	m_texture = std::make_shared<Texture>();
	m_texture->Init("..\\Data\\Textures\\btPlay.tga", GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);
	texture = std::make_shared<Texture>();

	m_model = std::make_shared<Models>();
	m_model->Init("..\\Data\\Model\\Sprite2D.nfg", NFG);
	model = std::make_shared<Models>();

	m_Sprite2D = new Sprite2D(m_model,m_Shaders,m_texture);
	m_Sprite2D->Set2DPosition(100, 50);
	m_Sprite2D->Init();
	camera = std::make_shared<Camera>();

	//camera
	Vector3 CameraPos(10, 40, 40);
	Vector3 TargetPos(0, 0, 0);
	float fFovY = 0.7f;
	m_Camera = std::make_shared<Camera>();
	m_Camera->Init(CameraPos, TargetPos, fFovY, (GLfloat)screenWidth / screenHeight, 1.0f, 5000.0f, 1.0f);


	//plan
	m_model = std::make_shared<Models>();
	m_model->Init("..\\Data\\Model\\Plan.nfg", NFG);
	m_Shaders = std::make_shared<Shaders>();
	m_Shaders->Init("..\\Data\\Shaders\\ColorShader.vs", "..\\Data\\Shaders\\TextureShader.fs");
	m_texture = std::make_shared<Texture>();
	m_texture->Init("..\\Data\\Textures\\Dirt.tga", GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);

	m_Plan = new Sprite3D(m_model, m_Shaders, m_Camera, m_texture);
	m_Plan->Set3DScale(Vector3(20, 20, 20));
	m_Plan->Init();

	//box
	m_model = std::make_shared<Models>();
	m_model->Init("..\\Data\\Model\\box.nfg", NFG);
	m_Shaders = std::make_shared<Shaders>();
	m_Shaders->Init("..\\Data\\Shaders\\ColorShader.vs", "..\\Data\\Shaders\\ColorShader.fs");

	m_Sprite3D = new Sprite3D(m_model, m_Shaders, m_Camera, Vector4(0.0, 0.0, 1.0, 0.5));
	m_Sprite3D->Set3DScale(Vector3(1, 1, 1));
	m_Sprite3D->Init();


	//cirle
	m_model = std::make_shared<Models>();
	m_model->Init("..\\Data\\Model\\Bila.nfg", NFG);

	m_Shaders = std::make_shared<Shaders>();
	m_Shaders->Init("..\\Data\\Shaders\\TextureShader.vs", "..\\Data\\Shaders\\TextureShader.fs");

	m_texture = std::make_shared<Texture>();
	m_texture->Init("..\\Data\\Textures\\Rock.tga", GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);

	m_Sprite3D1 = new Sprite3D(m_model, m_Shaders, m_Camera, m_texture);
	m_Sprite3D1->Init();
	m_Sprite3D1->Set3DScale(Vector3(0.05, 0.05, 0.05));
	m_Sprite3D1->SetShaders(m_Shaders);
	m_Sprite3D1->SetModels(m_model);
	m_Sprite3D1->SetColor(Vector4(0.0, 1.0, 1.0, 0.5));
	m_Sprite3D1->SetCamera(m_Camera);
}






void Application::Update(GLfloat deltaTime)
{
	//update
	m_Plan->Update(deltaTime);
	m_Sprite3D->Update(deltaTime);
	m_Sprite2D->Update(deltaTime);
	m_Sprite3D1->Update(deltaTime);
}

void Application::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Draw
	
	//3D
	m_Plan->Draw();
	m_Sprite3D->Draw();
	m_Sprite3D1->Draw();
	
	//2D
	m_Sprite2D->Draw();
}

void Application::HandleKeyEvent(unsigned char key, bool bIsPresseded)
{

}

void Application::HandleTouchEvent(GLint x, GLint y, bool bIsPresseded)
{
}

void Application::Exit()
{
	exit(0);
}
