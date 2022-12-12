# **Project_ScholarshipEvalSystem** 
>这个Markdown文件是写关于中南大学22级C语言课设（大作业）的更新日志  
>作者：orlenHJ 中南大学自动化院 22级  
>程序内容 选题6：学生奖学金评定系统  
>难度：4/10  
>运行环境 Visual Studio 2022
------
## **以下为程序课程设计作业的要求**
对学年奖学金进行公开透明的评定，要求输入每位申报学生的数据，包括：学号、姓名、
学习成绩绩点、学术成果积分、社会工作积分。具体计算公式如下：  
总评分：学习成绩绩点\*30%+学术成果计分\*60%+社会工作计分\*10%  


|  分数   | 学习成绩   |   论文数量   | 担任的干部职位   |  
|  ----   | ----  |  ----   | ----  |
|100| 4 |>5| 年级长、党支部书书记、学生会部长
|80| 3.7| 3| 班长、学生会副部长、党支部副书记
|70| 3.3| 2 |班委、党支部委员
|50| 2.7以上| 1| 无
----

|学号 |姓名 |学习成绩绩点 |论文数量 |社会工作 |总分
|----|----|----|----|----|----
|CSU202001 |张三 |3.0 |6 |班委
|CSU202111 |李四 |4.0 |4 |学生会部长
|CSU202121 |王五 |3.7 |2 |无
|CSU202051 |赵六 |4.0 |5 |党支部书记
|CSU202008 |陈七 |3.3 |1 |支委
----
## **编写的学生奖学金评定系统应该具有以下功能**
>* **输入功能**：输入学生相关信息，如：编号、姓名、学习成绩绩点、论文数量、项目
社会工作。（要求：① 至少输入 10 位学生的信息；② 可以在原有记录的基础上，添加新的
记录；③ 要求学号不能重复，输入过程中如果出现相同的学号，应给出报错信号，并重新
输入；④ 编号、姓名、项目社会工作要求用字符数组或字符指针；论文数量、等要求用整
数；学习成绩绩点、总分用实数，并且总分保留两位小数；  
>* **排序功能**：对所有录入的学生记录进行排序，并以表 2 的方式输出。（要求：至少提
供三种排序方式，如按学号排序、按姓名排序、按总分排序等。）  
>* **统计功能**：对学生的信息进行统计。（要求：自己设计统计表格的形式，但必须包括
以下统计信息：总成绩在前三的学生学号、姓名、学习成绩绩点、论文数量、项目社会工作
等）。  
>* **查询功能**：查找满足一定条件的学生信息，并将满足条件的学生所有信息（包括学
号、姓名、学习成绩绩点、论文数量、项目社会工作、总分）输出。（要求：① 提供三种查
询方式：按学号查询、按姓名查询、按总分是否在某个区间查询；② 如果满足条件的记录
有多条，应全部列出；③ 如果没有满足条件的记录，应给出相应的提示。）  
>* **修改功能**：输入学生学号，若存在，则可以对学生的评分表信息进行修改；如果该
不存在，必须有相应的提示。（要求：修改之前应再次确认是否修改。）   
>* **删除功能**：输入学生学号，若存在，删除其所有信息；否则，须有相应的提示。（要
求：删除之前应再次确认是否删除。）  
>* **退出系统**：退出系统之前，要再次确认。
>* **其他说明**：上述系统功能要求可能有些不是特别合理的地方，各位同学可以根据自
己的想法，设计系统功能，但所设计的系统功能数目不能少于上述要求。
---
## **以下为程序的更新日志相关内容**  
---
### **12.3更新日志 Ver0.1**
>* 实现系统要求的基本功能
>* 基本实现对应以总分、姓名、学号排序功能
>* 优化了修改学生信息的功能函数
### **12.5更新日志 Ver0.2.5**
>* 优化修改对应总分、姓名、学号排序功能  
>* 添加了对应学业成绩绩点、论文数量的排序功能
>* 优化了在修改学生信息的BUG
### **12.7更新日志 Ver0.3.4**  
>* 解决了`void DelStuInfo(void)`函数的BUG ，可以完美删除任何学生信息
>* 在非头结点函数里添加判断都数第二个的if，实现删除尾节点
  
    if (p->pNext->pNext == NULL) //证明是链表的倒数第二个，将指向最后一个的p->Next 为NULL
		{
			p2 = p->pNext;
			p->pNext = NULL;
			printf("删除成功！\n");
			free(p2);			
			system("pause");
			system("cls");
			return;
		}
		p = p->pNext;

### **12.8更新日志 Ver0.3.6.2**
>* 解决了`void ModifyStuInfo(void)`的部分BUG
>* 解决了`void DelStuInfo(void)`的写入'1'删除最后一位的BUG
>* `void ModifyStuInfo(void)`添加了可修改姓名信息  
### **12.10更新日志 Ver0.3.7**
>* 调整了输入学生信息的顺序
>* 排列学生信息时，做出了对应提示
>* 程序预备做课设中期验收

















