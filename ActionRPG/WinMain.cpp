#include"DxLib.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	int ModelHandle;

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

	SetDrawScreen(DX_SCREEN_BACK);

	ModelHandle = MV1LoadModel("image/unitychan.mv1");

	//�Q�[�����[�v
	while (true)
	{
		if (ProcessMessage() != 0)
		{
			break;
		}

		MV1SetPosition(ModelHandle, VGet(320.0f, -300.0f, 600.0f));

		//��ʃN���A
		ClearDrawScreen();
		clsDx();

		//��ʍX�V
		ScreenFlip();

	}

	// �R�c���f���̕`��
	MV1DrawModel(ModelHandle);

	// ���f���n���h���̍폜
	MV1DeleteModel(ModelHandle);

	DxLib_End();    // �c�w���C�u�����g�p�̏I������

	return 0;    // �\�t�g�̏I�� 
}