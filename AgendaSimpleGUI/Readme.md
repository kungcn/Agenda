# Readme
**Sorry because of time limit, I just write the readme.md in my mother language -- Chinese instead of English, so I will update it if I have spare time.**

## 用户需求文档
### Agenda Simple GUI的功能
1. 通过Web实现了Agenda会议管理系统的图形用户界面设计，采用的是html和css， 使得用户体验更好，而不是依赖于C++的黑框进行UI操作。与后台链接后就可以使用。
2. 因为时间及自身技术限制，并没有使用图片背景等等的，页面较简单，也没有做美工，这是不足之处。

### Agenda Simple GUI的各个文件的介绍
* AgendaFirstPage.html为整个系统的首页，应从此页开始体验。
* AgendaRegister.html为系统注册页面，为注册用户应先按网页要求填写相关信息后进行验证。
* AgendaRegistering.html为注册后的验证页面，用户在自己的注册邮箱里找到系统发出邮件的验证码，并且在该页面输入，经系统验证无误后，方完成注册。
* AgendaLogin.html为登录页面，已注册的用户可以点击该页面登录后直接进入系统。
* AgendaUserFirstPage.html为用户主页，用户可以看到“欢迎回来！”的字样。
* AgendaCreateMeeting.html为创建会议页面，已登录用户可以点击此页面后输入会议主题，受邀者，会议开始和结束时间后可以创建页面。
* AgendaSearchMeeting.html为查找会议页面，用户可以用过输入会议主题或者会议的开始和结束时间查询相关会议。因为没有后台，所以按下“查询”按钮后自动返回“用户主页”。
* AgendaCreatedMeeting.html为列出已创建的会议的页面。
* AgendaParticipatedMeeting.html为列出已受邀的会议的页面。
* AgendaDeleteMeeting.html为删除已创建会议的页面，用户可以输入会议主题删除会议或者选择删除自己创建的全部会议。因为没有后台，所以按下“查询”按钮后自动返回“用户主页”。
* AgendaDeleteUser.html为注销用户账号的页面，用户可以按下按钮后注销自己的账号并删去该账号在后台的所有数据。
* AgendaLogOut.html为用户下线退出账号的页面。
* AgendaSimpleGUI.css为以上所有html文件的css格式来源。
* SYSU.jpg为系统的那个图标(icon)，因为时间关系和图片版权问题，所以没有找其他图片而是这一张。
* SecurityCode.png为登录页面的验证码图片，取自新浪微博登录的验证码图片。

### 关于html和css文件的说明
* 全部的网页都经过w3c的html和css检测，每个html文件都是有2个warning, 一个是永远存在的warning(表示虽然通过了测试但仍然可能有错误的一个warning),另外一个我也是第一次看到的，大概是我不知道哪里混进了html5语法，但是我并不会如何改进。
* 由于时间关系，所以css文件内各选择器内的语句顺序可能写得并不规范，css代码的可维护性会降低，抱歉。

学号：14331074
姓名：龚俊宁
