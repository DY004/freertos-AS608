#include "as608_test.h"
#include <stdio.h>
#include "as608.h"




void Show_Message(void)
{
    printf("   请输入指令，输入指令后请在输入窗口按回车键后再发送指令！！！\r\n");
    printf("   指令   ------      功能 \r\n");
    printf("    1     ------    添加指纹 \r\n");
    printf("    2     ------    对比指纹 \r\n");
    printf("    3     ------    删除指定用户指纹\r\n");
    printf("    4     ------    清空指纹库\r\n");
}





/**
  * @brief  指纹模块操作
  * @param  无
  * @retval 无
  */
void  FR_Task(void)
{
    uint32_t   ch;
    scanf("%d",&ch);

    printf("接收到字符：%d\r\n",ch);

    switch(ch)
    {
    case 1:
		ch = 0;
        Add_FR();                                    /*添加指纹*/
        Show_Message();
        break;

    case 2:
		ch = 0;
        press_FR();                                /*比对指纹*/
        Show_Message();
        break;

    case 3:
		ch = 0;
        Del_FR();                                    /*删除指定用户指纹*/
        Show_Message();
        break;

    case 4:
		ch = 0;
        Del_FR_Lib();                                  /*清空指纹库*/
        Show_Message();
        break;

    default:
        /* 如果不是指定指令字符，打印提示信息 */
        printf("请输入合法指令！\r\n\r\n");
        Show_Message();
        break;
    }
	
    return;
}



