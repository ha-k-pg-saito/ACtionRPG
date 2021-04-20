#ifndef Graphics_h_
#define Graphics_h_

class Graphics
{
public:
	static Graphics* Instance()
	{
		static Graphics instance;

		return &instance;
	}

private:
	void InitTexture();
	void ReleaseTexture();

private:
	//�C���X�^���X����h�����߂̏���
	Graphics() {}
};

#endif