#include "DxLib.h"
#include "h/Player.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	Player player;  // PlayerClass�̃��[�J���ϐ�

	//�E�C���h�E���[�h�ɕύX
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);				//�E�B���h�E���[�h
	SetGraphMode(640, 480, 32);		//��ʃ��[�h�ύX
	SetBackgroundColor(0, 0, 0);	//�w�i�F
	SetFontSize(75);					//�t�H���g�T�C�Y
	SetCameraNearFar(1.f,150.f);

	if (DxLib_Init() == -1)  // �c�w���C�u��������������
	{
		return -1;   // �G���[���N�����璼���ɏI��
	}

	player.Update();           // Player�̎��s�֐�

	//�Q�[�����[�v
	while (true)
	{
		if (ProcessMessage() != 0)
		{
			break;
		}

		//��ʃN���A
		ClearDrawScreen();

		player.Draw();          // Player�̕`��֐�

		//clsDx();

		//��ʍX�V
		ScreenFlip();

	}

	SetDrawScreen(DX_SCREEN_BACK);

	DxLib_End();    // �c�w���C�u�����g�p�̏I������

	return 0;    // �\�t�g�̏I�� 
}