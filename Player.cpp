#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	//モデルを初期化する。
	modelRender.Init("Assets/modelData/unityChan.tkm");
}

Player::~Player()
{

}

void Player::Update()
{
	//Hands On 1 キャラクターを左右に動かしてみよう。
	if (g_pad[0]->IsPress(enButtonRight) && g_pad[0]->IsPress(enButtonB)) {
		position.x += 20.0f;
		//キーボードの6.Kキー
	}
	if (g_pad[0]->IsPress(enButtonRight)){
			position.x += 10.0f;
		}
	

	if (g_pad[0]->IsPress(enButtonLeft))
	{               //キーボードの４キー
		position.x -= 10.0f;
	}
	//Hands On 2 キャラクターを複製してみよう。
	if (g_pad[0]->IsPress(enButtonSelect))
	{    //キーボードのスペースキー
		NewGO<Player>(0);
	}
	//Hands On 3 キャラクターをジャンプさせてみよう。
	if (g_pad[0]->IsPress(enButtonA))
	{//キーボードのｊキー
		position.y += 5.0f;
	}
	//実習課題 1 ゲームパッドの上ボタンが押されたら奥に。
	//下ボタンが押されたら手前にキャラクターが動くようにしよう。
	//上ボタンはenButtonUp、下ボタンはenButtonDownです。
	
	//Hands On 4 重力を加えてみよう。
	position.y -= 0.5f;

	//Hands On 5 キャラクターのy座標を制限してみよう。
	if (position.y <= 0.0f)
	{
		position.y = 0.0f;
	}
	{
	}
	//座標を絵描きさんに教える。
	modelRender.SetPosition(position);

	//モデルを更新する。
	modelRender.Update();
}

void Player::Render(RenderContext& renderContext)
{
	//モデルを表示する。
	modelRender.Draw(renderContext);
}
