# TDOA
Implementation Of TDOA Using Chan Algorithm And Taylor Algorithm in 3D space  
Author:HaoyaWHL<br>  
Finish Time:2016/5 when I was masterGrade 1<br>  
Implement：Visual Studio 2013 in C++<br>  

-------------------------------------------

## 2018.11.23更新

这是2016年研一的时候独立承担的工程，应用场景中包含四个基站，在PC上通过8888号端口获取数据

由于解码问题，所以main.cpp中把原始数据从16进制->2进制->10进制，再进行处理

原理是采用了CHAN氏算法：4个基站ABCD，BCD分别与A构建三个双曲线方程，运用最小二乘两次求解（第一次最小二乘是为了估计噪声）

可以直接求解XYZ坐标，但是因为Z方向精度问题，先求解XY，再暴力求解Z

-------------------------------------------

## 2019.04.15更新（重要）

一般现有论文中提及的chan式算法，是三个基站求解XY坐标（但是我当时阅读相关文章的时候发现很多公式推导有些许差异，所以建议大家自行推导一遍）。

我重新推演公式到4基站求解XYZ坐标（假设此时方程式为A），但这个时候发现Z方向精度不足，所以我的做法是先构建两个双曲线方程求解XY坐标，然后把XY代入方程式A中，即求解一元一次方程。

不过这样的做法仍然存在精度不足的原因，计算过程比较粗糙，所以我用“暴力”一词来描述Z的求解。

【更新文件说明】

附件liwenhaoTDOA.rar为我的仿真代码

先看XY_TDOA.m（这个文件求解XY坐标），然后看Z_Cal_Simulation.m（已知XY求解Z坐标），我就是基于此进行的C++实现。

【误差说明】

泰勒算法在整个定位过程中起到作用小到可以忽略，主要看Chan式算法就行，误差也主要是这个算法中产生的

因为是在实验环境做的，推演Z坐标在实际环境估计有0.5~1.5M的误差，X和Y坐标大约有0.5M的误差，具体情况看我实验数据

【实验数据说明】

其中BS表示的是Base Station，单位为cm

delay表示基站到PC的电缆延迟，单位为ns，数据已知

文件夹“2016.5.6调试代码-重要数据”，可以看到四个伪基站的坐标以及分布情况，其中：  

a.txt 为原始数据，以10Hz频率写入192.168.0.32:8888，表示当前四个基站与PC交互时间点信息（编码格式我找不到了）  

b.txt为针对a.txt处理的数据，表示当前四个基站与PC交互时间点信息，单位是us（这个单位是否为us需要你自己验证，我找不到数据说明了）  
以某一行数据为例164483.3602905 164476.8829346 164493.0419922 164489.2501831  
表明在164483.3602905这个时间点信号接收方（PC）收到来自1号基站的信息  
在164476.8829346这个时间点信号接收方（PC）收到来自2号基站的信息  
在164493.0419922这个时间点信号接收方（PC）收到来自3号基站的信息  
在164489.2501831这个时间点信号接收方（PC）收到来自4号基站的信息  

根据TDOA算法，我们求解其余三个基站与基站1的到达时间差，从而构建双曲线方程，就可以求解目标的三维坐标  


