package com.elex.chatservice.util;

import java.util.HashMap;

public class HSCharacters8
{
  HashMap<Integer, String[]> characters;

  public boolean containsKey(int high, int low)
  {
    String[] entries = (String[])this.characters.get(Integer.valueOf(high));
    return (entries != null) && (low < entries.length) && (entries[low].length() > 0);
  }

  public String get(int high, int low) {
    String[] entries = (String[])this.characters.get(Integer.valueOf(high));
    return entries[low];
  }

  public HSCharacters8() {
    this.characters = new HashMap();
    this.characters.put(Integer.valueOf(121), new String[] { "Tani ", "Jiao ", "[?] ", "Zhang ", "Qiao ", "Dun ", "Xian ", "Yu ", "Zhui ", "He ", "Huo ", "Zhai ", "Lei ", "Ke ", "Chu ", "Ji ", "Que ", "Dang ", "Yi ", "Jiang ", "Pi ", "Pi ", "Yu ", "Pin ", "Qi ", "Ai ", "Kai ", "Jian ", "Yu ", "Ruan ", "Meng ", "Pao ", "Ci ", "[?] ", "[?] ", "Mie ", "Ca ", "Xian ", "Kuang ", "Lei ", "Lei ", "Zhi ", "Li ", "Li ", "Fan ", "Que ", "Pao ", "Ying ", "Li ", "Long ", "Long ", "Mo ", "Bo ", "Shuang ", "Guan ", "Lan ", "Zan ", "Yan ", "Shi ", "Shi ", "Li ", "Reng ", "She ", "Yue ", "Si ", "Qi ", "Ta ", "Ma ", "Xie ", "Xian ", "Xian ", "Zhi ", "Qi ", "Zhi ", "Beng ", "Dui ", "Zhong ", "[?] ", "Yi ", "Shi ", "You ", "Zhi ", "Tiao ", "Fu ", "Fu ", "Mi ", "Zu ", "Zhi ", "Suan ", "Mei ", "Zuo ", "Qu ", "Hu ", "Zhu ", "Shen ", "Sui ", "Ci ", "Chai ", "Mi ", "Lu ", "Yu ", "Xiang ", "Wu ", "Tiao ", "Piao ", "Zhu ", "Gui ", "Xia ", "Zhi ", "Ji ", "Gao ", "Zhen ", "Gao ", "Shui ", "Jin ", "Chen ", "Gai ", "Kun ", "Di ", "Dao ", "Huo ", "Tao ", "Qi ", "Gu ", "Guan ", "Zui ", "Ling ", "Lu ", "Bing ", "Jin ", "Dao ", "Zhi ", "Lu ", "Shan ", "Bei ", "Zhe ", "Hui ", "You ", "Xi ", "Yin ", "Zi ", "Huo ", "Zhen ", "Fu ", "Yuan ", "Wu ", "Xian ", "Yang ", "Ti ", "Yi ", "Mei ", "Si ", "Di ", "[?] ", "Zhuo ", "Zhen ", "Yong ", "Ji ", "Gao ", "Tang ", "Si ", "Ma ", "Ta ", "[?] ", "Xuan ", "Qi ", "Yu ", "Xi ", "Ji ", "Si ", "Chan ", "Tan ", "Kuai ", "Sui ", "Li ", "Nong ", "Ni ", "Dao ", "Li ", "Rang ", "Yue ", "Ti ", "Zan ", "Lei ", "Rou ", "Yu ", "Yu ", "Chi ", "Xie ", "Qin ", "He ", "Tu ", "Xiu ", "Si ", "Ren ", "Tu ", "Zi ", "Cha ", "Gan ", "Yi ", "Xian ", "Bing ", "Nian ", "Qiu ", "Qiu ", "Chong ", "Fen ", "Hao ", "Yun ", "Ke ", "Miao ", "Zhi ", "Geng ", "Bi ", "Zhi ", "Yu ", "Mi ", "Ku ", "Ban ", "Pi ", "Ni ", "Li ", "You ", "Zu ", "Pi ", "Ba ", "Ling ", "Mo ", "Cheng ", "Nian ", "Qin ", "Yang ", "Zuo ", "Zhi ", "Zhi ", "Shu ", "Ju ", "Zi ", "Huo ", "Ji ", "Cheng ", "Tong ", "Zhi ", "Huo ", "He ", "Yin ", "Zi ", "Zhi ", "Jie ", "Ren ", "Du ", "Yi ", "Zhu ", "Hui ", "Nong ", "Fu " });

    this.characters.put(Integer.valueOf(122), new String[] { "Xi ", "Kao ", "Lang ", "Fu ", "Ze ", "Shui ", "Lu ", "Kun ", "Gan ", "Geng ", "Ti ", "Cheng ", "Tu ", "Shao ", "Shui ", "Ya ", "Lun ", "Lu ", "Gu ", "Zuo ", "Ren ", "Zhun ", "Bang ", "Bai ", "Ji ", "Zhi ", "Zhi ", "Kun ", "Leng ", "Peng ", "Ke ", "Bing ", "Chou ", "Zu ", "Yu ", "Su ", "Lue ", "[?] ", "Yi ", "Xi ", "Bian ", "Ji ", "Fu ", "Bi ", "Nuo ", "Jie ", "Zhong ", "Zong ", "Xu ", "Cheng ", "Dao ", "Wen ", "Lian ", "Zi ", "Yu ", "Ji ", "Xu ", "Zhen ", "Zhi ", "Dao ", "Jia ", "Ji ", "Gao ", "Gao ", "Gu ", "Rong ", "Sui ", "You ", "Ji ", "Kang ", "Mu ", "Shan ", "Men ", "Zhi ", "Ji ", "Lu ", "Su ", "Ji ", "Ying ", "Wen ", "Qiu ", "Se ", "[?] ", "Yi ", "Huang ", "Qie ", "Ji ", "Sui ", "Xiao ", "Pu ", "Jiao ", "Zhuo ", "Tong ", "Sai ", "Lu ", "Sui ", "Nong ", "Se ", "Hui ", "Rang ", "Nuo ", "Yu ", "Bin ", "Ji ", "Tui ", "Wen ", "Cheng ", "Huo ", "Gong ", "Lu ", "Biao ", "[?] ", "Rang ", "Zhuo ", "Li ", "Zan ", "Xue ", "Wa ", "Jiu ", "Qiong ", "Xi ", "Qiong ", "Kong ", "Yu ", "Sen ", "Jing ", "Yao ", "Chuan ", "Zhun ", "Tu ", "Lao ", "Qie ", "Zhai ", "Yao ", "Bian ", "Bao ", "Yao ", "Bing ", "Wa ", "Zhu ", "Jiao ", "Qiao ", "Diao ", "Wu ", "Gui ", "Yao ", "Zhi ", "Chuang ", "Yao ", "Tiao ", "Jiao ", "Chuang ", "Jiong ", "Xiao ", "Cheng ", "Kou ", "Cuan ", "Wo ", "Dan ", "Ku ", "Ke ", "Zhui ", "Xu ", "Su ", "Guan ", "Kui ", "Dou ", "[?] ", "Yin ", "Wo ", "Wa ", "Ya ", "Yu ", "Ju ", "Qiong ", "Yao ", "Yao ", "Tiao ", "Chao ", "Yu ", "Tian ", "Diao ", "Ju ", "Liao ", "Xi ", "Wu ", "Kui ", "Chuang ", "Zhao ", "[?] ", "Kuan ", "Long ", "Cheng ", "Cui ", "Piao ", "Zao ", "Cuan ", "Qiao ", "Qiong ", "Dou ", "Zao ", "Long ", "Qie ", "Li ", "Chu ", "Shi ", "Fou ", "Qian ", "Chu ", "Hong ", "Qi ", "Qian ", "Gong ", "Shi ", "Shu ", "Miao ", "Ju ", "Zhan ", "Zhu ", "Ling ", "Long ", "Bing ", "Jing ", "Jing ", "Zhang ", "Yi ", "Si ", "Jun ", "Hong ", "Tong ", "Song ", "Jing ", "Diao ", "Yi ", "Shu ", "Jing ", "Qu ", "Jie ", "Ping ", "Duan ", "Shao ", "Zhuan ", "Ceng ", "Deng ", "Cui ", "Huai ", "Jing ", "Kan ", "Jing ", "Zhu ", "Zhu ", "Le ", "Peng ", "Yu ", "Chi ", "Gan " });

    this.characters.put(Integer.valueOf(123), new String[] { "Mang ", "Zhu ", "Utsubo ", "Du ", "Ji ", "Xiao ", "Ba ", "Suan ", "Ji ", "Zhen ", "Zhao ", "Sun ", "Ya ", "Zhui ", "Yuan ", "Hu ", "Gang ", "Xiao ", "Cen ", "Pi ", "Bi ", "Jian ", "Yi ", "Dong ", "Shan ", "Sheng ", "Xia ", "Di ", "Zhu ", "Na ", "Chi ", "Gu ", "Li ", "Qie ", "Min ", "Bao ", "Tiao ", "Si ", "Fu ", "Ce ", "Ben ", "Pei ", "Da ", "Zi ", "Di ", "Ling ", "Ze ", "Nu ", "Fu ", "Gou ", "Fan ", "Jia ", "Ge ", "Fan ", "Shi ", "Mao ", "Po ", "Sey ", "Jian ", "Qiong ", "Long ", "Souke ", "Bian ", "Luo ", "Gui ", "Qu ", "Chi ", "Yin ", "Yao ", "Xian ", "Bi ", "Qiong ", "Gua ", "Deng ", "Jiao ", "Jin ", "Quan ", "Sun ", "Ru ", "Fa ", "Kuang ", "Zhu ", "Tong ", "Ji ", "Da ", "Xing ", "Ce ", "Zhong ", "Kou ", "Lai ", "Bi ", "Shai ", "Dang ", "Zheng ", "Ce ", "Fu ", "Yun ", "Tu ", "Pa ", "Li ", "Lang ", "Ju ", "Guan ", "Jian ", "Han ", "Tong ", "Xia ", "Zhi ", "Cheng ", "Suan ", "Shi ", "Zhu ", "Zuo ", "Xiao ", "Shao ", "Ting ", "Ce ", "Yan ", "Gao ", "Kuai ", "Gan ", "Chou ", "Kago ", "Gang ", "Yun ", "O ", "Qian ", "Xiao ", "Jian ", "Pu ", "Lai ", "Zou ", "Bi ", "Bi ", "Bi ", "Ge ", "Chi ", "Guai ", "Yu ", "Jian ", "Zhao ", "Gu ", "Chi ", "Zheng ", "Jing ", "Sha ", "Zhou ", "Lu ", "Bo ", "Ji ", "Lin ", "Suan ", "Jun ", "Fu ", "Zha ", "Gu ", "Kong ", "Qian ", "Quan ", "Jun ", "Chui ", "Guan ", "Yuan ", "Ce ", "Ju ", "Bo ", "Ze ", "Qie ", "Tuo ", "Luo ", "Dan ", "Xiao ", "Ruo ", "Jian ", "Xuan ", "Bian ", "Sun ", "Xiang ", "Xian ", "Ping ", "Zhen ", "Sheng ", "Hu ", "Shi ", "Zhu ", "Yue ", "Chun ", "Lu ", "Wu ", "Dong ", "Xiao ", "Ji ", "Jie ", "Huang ", "Xing ", "Mei ", "Fan ", "Chui ", "Zhuan ", "Pian ", "Feng ", "Zhu ", "Hong ", "Qie ", "Hou ", "Qiu ", "Miao ", "Qian ", "[?] ", "Kui ", "Sik ", "Lou ", "Yun ", "He ", "Tang ", "Yue ", "Chou ", "Gao ", "Fei ", "Ruo ", "Zheng ", "Gou ", "Nie ", "Qian ", "Xiao ", "Cuan ", "Gong ", "Pang ", "Du ", "Li ", "Bi ", "Zhuo ", "Chu ", "Shai ", "Chi ", "Zhu ", "Qiang ", "Long ", "Lan ", "Jian ", "Bu ", "Li ", "Hui ", "Bi ", "Di ", "Cong ", "Yan ", "Peng ", "Sen ", "Zhuan ", "Pai ", "Piao ", "Dou ", "Yu ", "Mie ", "Zhuan " });

    this.characters.put(Integer.valueOf(124), new String[] { "Ze ", "Xi ", "Guo ", "Yi ", "Hu ", "Chan ", "Kou ", "Cu ", "Ping ", "Chou ", "Ji ", "Gui ", "Su ", "Lou ", "Zha ", "Lu ", "Nian ", "Suo ", "Cuan ", "Sasara ", "Suo ", "Le ", "Duan ", "Yana ", "Xiao ", "Bo ", "Mi ", "Si ", "Dang ", "Liao ", "Dan ", "Dian ", "Fu ", "Jian ", "Min ", "Kui ", "Dai ", "Qiao ", "Deng ", "Huang ", "Sun ", "Lao ", "Zan ", "Xiao ", "Du ", "Shi ", "Zan ", "[?] ", "Pai ", "Hata ", "Pai ", "Gan ", "Ju ", "Du ", "Lu ", "Yan ", "Bo ", "Dang ", "Sai ", "Ke ", "Long ", "Qian ", "Lian ", "Bo ", "Zhou ", "Lai ", "[?] ", "Lan ", "Kui ", "Yu ", "Yue ", "Hao ", "Zhen ", "Tai ", "Ti ", "Mi ", "Chou ", "Ji ", "[?] ", "Hata ", "Teng ", "Zhuan ", "Zhou ", "Fan ", "Sou ", "Zhou ", "Kuji ", "Zhuo ", "Teng ", "Lu ", "Lu ", "Jian ", "Tuo ", "Ying ", "Yu ", "Lai ", "Long ", "Shinshi ", "Lian ", "Lan ", "Qian ", "Yue ", "Zhong ", "Qu ", "Lian ", "Bian ", "Duan ", "Zuan ", "Li ", "Si ", "Luo ", "Ying ", "Yue ", "Zhuo ", "Xu ", "Mi ", "Di ", "Fan ", "Shen ", "Zhe ", "Shen ", "Nu ", "Xie ", "Lei ", "Xian ", "Zi ", "Ni ", "Cun ", "[?] ", "Qian ", "Kume ", "Bi ", "Ban ", "Wu ", "Sha ", "Kang ", "Rou ", "Fen ", "Bi ", "Cui ", "[?] ", "Li ", "Chi ", "Nukamiso ", "Ro ", "Ba ", "Li ", "Gan ", "Ju ", "Po ", "Mo ", "Cu ", "Nian ", "Zhou ", "Li ", "Su ", "Tiao ", "Li ", "Qi ", "Su ", "Hong ", "Tong ", "Zi ", "Ce ", "Yue ", "Zhou ", "Lin ", "Zhuang ", "Bai ", "[?] ", "Fen ", "Ji ", "[?] ", "Sukumo ", "Liang ", "Xian ", "Fu ", "Liang ", "Can ", "Geng ", "Li ", "Yue ", "Lu ", "Ju ", "Qi ", "Cui ", "Bai ", "Zhang ", "Lin ", "Zong ", "Jing ", "Guo ", "Kouji ", "San ", "San ", "Tang ", "Bian ", "Rou ", "Mian ", "Hou ", "Xu ", "Zong ", "Hu ", "Jian ", "Zan ", "Ci ", "Li ", "Xie ", "Fu ", "Ni ", "Bei ", "Gu ", "Xiu ", "Gao ", "Tang ", "Qiu ", "Sukumo ", "Cao ", "Zhuang ", "Tang ", "Mi ", "San ", "Fen ", "Zao ", "Kang ", "Jiang ", "Mo ", "San ", "San ", "Nuo ", "Xi ", "Liang ", "Jiang ", "Kuai ", "Bo ", "Huan ", "[?] ", "Zong ", "Xian ", "Nuo ", "Tuan ", "Nie ", "Li ", "Zuo ", "Di ", "Nie ", "Tiao ", "Lan ", "Mi ", "Jiao ", "Jiu ", "Xi ", "Gong ", "Zheng ", "Jiu ", "You " });

    this.characters.put(Integer.valueOf(125), new String[] { "Ji ", "Cha ", "Zhou ", "Xun ", "Yue ", "Hong ", "Yu ", "He ", "Wan ", "Ren ", "Wen ", "Wen ", "Qiu ", "Na ", "Zi ", "Tou ", "Niu ", "Fou ", "Jie ", "Shu ", "Chun ", "Pi ", "Yin ", "Sha ", "Hong ", "Zhi ", "Ji ", "Fen ", "Yun ", "Ren ", "Dan ", "Jin ", "Su ", "Fang ", "Suo ", "Cui ", "Jiu ", "Zha ", "Kinu ", "Jin ", "Fu ", "Zhi ", "Ci ", "Zi ", "Chou ", "Hong ", "Zha ", "Lei ", "Xi ", "Fu ", "Xie ", "Shen ", "Bei ", "Zhu ", "Qu ", "Ling ", "Zhu ", "Shao ", "Gan ", "Yang ", "Fu ", "Tuo ", "Zhen ", "Dai ", "Zhuo ", "Shi ", "Zhong ", "Xian ", "Zu ", "Jiong ", "Ban ", "Ju ", "Mo ", "Shu ", "Zui ", "Wata ", "Jing ", "Ren ", "Heng ", "Xie ", "Jie ", "Zhu ", "Chou ", "Gua ", "Bai ", "Jue ", "Kuang ", "Hu ", "Ci ", "Geng ", "Geng ", "Tao ", "Xie ", "Ku ", "Jiao ", "Quan ", "Gai ", "Luo ", "Xuan ", "Bing ", "Xian ", "Fu ", "Gei ", "Tong ", "Rong ", "Tiao ", "Yin ", "Lei ", "Xie ", "Quan ", "Xu ", "Lun ", "Die ", "Tong ", "Si ", "Jiang ", "Xiang ", "Hui ", "Jue ", "Zhi ", "Jian ", "Juan ", "Chi ", "Mian ", "Zhen ", "Lu ", "Cheng ", "Qiu ", "Shu ", "Bang ", "Tong ", "Xiao ", "Wan ", "Qin ", "Geng ", "Xiu ", "Ti ", "Xiu ", "Xie ", "Hong ", "Xi ", "Fu ", "Ting ", "Sui ", "Dui ", "Kun ", "Fu ", "Jing ", "Hu ", "Zhi ", "Yan ", "Jiong ", "Feng ", "Ji ", "Sok ", "Kase ", "Zong ", "Lin ", "Duo ", "Li ", "Lu ", "Liang ", "Chou ", "Quan ", "Shao ", "Qi ", "Qi ", "Zhun ", "Qi ", "Wan ", "Qian ", "Xian ", "Shou ", "Wei ", "Qi ", "Tao ", "Wan ", "Gang ", "Wang ", "Beng ", "Zhui ", "Cai ", "Guo ", "Cui ", "Lun ", "Liu ", "Qi ", "Zhan ", "Bei ", "Chuo ", "Ling ", "Mian ", "Qi ", "Qie ", "Tan ", "Zong ", "Gun ", "Zou ", "Yi ", "Zi ", "Xing ", "Liang ", "Jin ", "Fei ", "Rui ", "Min ", "Yu ", "Zong ", "Fan ", "Lu ", "Xu ", "Yingl ", "Zhang ", "Kasuri ", "Xu ", "Xiang ", "Jian ", "Ke ", "Xian ", "Ruan ", "Mian ", "Qi ", "Duan ", "Zhong ", "Di ", "Min ", "Miao ", "Yuan ", "Xie ", "Bao ", "Si ", "Qiu ", "Bian ", "Huan ", "Geng ", "Cong ", "Mian ", "Wei ", "Fu ", "Wei ", "Yu ", "Gou ", "Miao ", "Xie ", "Lian ", "Zong ", "Bian ", "Yun ", "Yin ", "Ti ", "Gua ", "Zhi ", "Yun ", "Cheng ", "Chan ", "Dai " });

    this.characters.put(Integer.valueOf(126), new String[] { "Xia ", "Yuan ", "Zong ", "Xu ", "Nawa ", "Odoshi ", "Geng ", "Sen ", "Ying ", "Jin ", "Yi ", "Zhui ", "Ni ", "Bang ", "Gu ", "Pan ", "Zhou ", "Jian ", "Cuo ", "Quan ", "Shuang ", "Yun ", "Xia ", "Shuai ", "Xi ", "Rong ", "Tao ", "Fu ", "Yun ", "Zhen ", "Gao ", "Ru ", "Hu ", "Zai ", "Teng ", "Xian ", "Su ", "Zhen ", "Zong ", "Tao ", "Horo ", "Cai ", "Bi ", "Feng ", "Cu ", "Li ", "Suo ", "Yin ", "Xi ", "Zong ", "Lei ", "Zhuan ", "Qian ", "Man ", "Zhi ", "Lu ", "Mo ", "Piao ", "Lian ", "Mi ", "Xuan ", "Zong ", "Ji ", "Shan ", "Sui ", "Fan ", "Shuai ", "Beng ", "Yi ", "Sao ", "Mou ", "Zhou ", "Qiang ", "Hun ", "Sem ", "Xi ", "Jung ", "Xiu ", "Ran ", "Xuan ", "Hui ", "Qiao ", "Zeng ", "Zuo ", "Zhi ", "Shan ", "San ", "Lin ", "Yu ", "Fan ", "Liao ", "Chuo ", "Zun ", "Jian ", "Rao ", "Chan ", "Rui ", "Xiu ", "Hui ", "Hua ", "Zuan ", "Xi ", "Qiang ", "Un ", "Da ", "Sheng ", "Hui ", "Xi ", "Se ", "Jian ", "Jiang ", "Huan ", "Zao ", "Cong ", "Jie ", "Jiao ", "Bo ", "Chan ", "Yi ", "Nao ", "Sui ", "Yi ", "Shai ", "Xu ", "Ji ", "Bin ", "Qian ", "Lan ", "Pu ", "Xun ", "Zuan ", "Qi ", "Peng ", "Li ", "Mo ", "Lei ", "Xie ", "Zuan ", "Kuang ", "You ", "Xu ", "Lei ", "Xian ", "Chan ", "Kou ", "Lu ", "Chan ", "Ying ", "Cai ", "Xiang ", "Xian ", "Zui ", "Zuan ", "Luo ", "Xi ", "Dao ", "Lan ", "Lei ", "Lian ", "Si ", "Jiu ", "Yu ", "Hong ", "Zhou ", "Xian ", "He ", "Yue ", "Ji ", "Wan ", "Kuang ", "Ji ", "Ren ", "Wei ", "Yun ", "Hong ", "Chun ", "Pi ", "Sha ", "Gang ", "Na ", "Ren ", "Zong ", "Lun ", "Fen ", "Zhi ", "Wen ", "Fang ", "Zhu ", "Yin ", "Niu ", "Shu ", "Xian ", "Gan ", "Xie ", "Fu ", "Lian ", "Zu ", "Shen ", "Xi ", "Zhi ", "Zhong ", "Zhou ", "Ban ", "Fu ", "Zhuo ", "Shao ", "Yi ", "Jing ", "Dai ", "Bang ", "Rong ", "Jie ", "Ku ", "Rao ", "Die ", "Heng ", "Hui ", "Gei ", "Xuan ", "Jiang ", "Luo ", "Jue ", "Jiao ", "Tong ", "Geng ", "Xiao ", "Juan ", "Xiu ", "Xi ", "Sui ", "Tao ", "Ji ", "Ti ", "Ji ", "Xu ", "Ling ", "[?] ", "Xu ", "Qi ", "Fei ", "Chuo ", "Zhang ", "Gun ", "Sheng ", "Wei ", "Mian ", "Shou ", "Beng ", "Chou ", "Tao ", "Liu ", "Quan ", "Zong ", "Zhan ", "Wan ", "Lu " });

    this.characters.put(Integer.valueOf(127), new String[] { "Zhui ", "Zi ", "Ke ", "Xiang ", "Jian ", "Mian ", "Lan ", "Ti ", "Miao ", "Qi ", "Yun ", "Hui ", "Si ", "Duo ", "Duan ", "Bian ", "Xian ", "Gou ", "Zhui ", "Huan ", "Di ", "Lu ", "Bian ", "Min ", "Yuan ", "Jin ", "Fu ", "Ru ", "Zhen ", "Feng ", "Shuai ", "Gao ", "Chan ", "Li ", "Yi ", "Jian ", "Bin ", "Piao ", "Man ", "Lei ", "Ying ", "Suo ", "Mou ", "Sao ", "Xie ", "Liao ", "Shan ", "Zeng ", "Jiang ", "Qian ", "Zao ", "Huan ", "Jiao ", "Zuan ", "Fou ", "Xie ", "Gang ", "Fou ", "Que ", "Fou ", "Kaakeru ", "Bo ", "Ping ", "Hou ", "[?] ", "Gang ", "Ying ", "Ying ", "Qing ", "Xia ", "Guan ", "Zun ", "Tan ", "Chang ", "Qi ", "Weng ", "Ying ", "Lei ", "Tan ", "Lu ", "Guan ", "Wang ", "Wang ", "Gang ", "Wang ", "Han ", "[?] ", "Luo ", "Fu ", "Mi ", "Fa ", "Gu ", "Zhu ", "Ju ", "Mao ", "Gu ", "Min ", "Gang ", "Ba ", "Gua ", "Ti ", "Juan ", "Fu ", "Lin ", "Yan ", "Zhao ", "Zui ", "Gua ", "Zhuo ", "Yu ", "Zhi ", "An ", "Fa ", "Nan ", "Shu ", "Si ", "Pi ", "Ma ", "Liu ", "Ba ", "Fa ", "Li ", "Chao ", "Wei ", "Bi ", "Ji ", "Zeng ", "Tong ", "Liu ", "Ji ", "Juan ", "Mi ", "Zhao ", "Luo ", "Pi ", "Ji ", "Ji ", "Luan ", "Yang ", "Mie ", "Qiang ", "Ta ", "Mei ", "Yang ", "You ", "You ", "Fen ", "Ba ", "Gao ", "Yang ", "Gu ", "Qiang ", "Zang ", "Gao ", "Ling ", "Yi ", "Zhu ", "Di ", "Xiu ", "Qian ", "Yi ", "Xian ", "Rong ", "Qun ", "Qun ", "Qian ", "Huan ", "Zui ", "Xian ", "Yi ", "Yashinau ", "Qiang ", "Xian ", "Yu ", "Geng ", "Jie ", "Tang ", "Yuan ", "Xi ", "Fan ", "Shan ", "Fen ", "Shan ", "Lian ", "Lei ", "Geng ", "Nou ", "Qiang ", "Chan ", "Yu ", "Gong ", "Yi ", "Chong ", "Weng ", "Fen ", "Hong ", "Chi ", "Chi ", "Cui ", "Fu ", "Xia ", "Pen ", "Yi ", "La ", "Yi ", "Pi ", "Ling ", "Liu ", "Zhi ", "Qu ", "Xi ", "Xie ", "Xiang ", "Xi ", "Xi ", "Qi ", "Qiao ", "Hui ", "Hui ", "Xiao ", "Se ", "Hong ", "Jiang ", "Di ", "Cui ", "Fei ", "Tao ", "Sha ", "Chi ", "Zhu ", "Jian ", "Xuan ", "Shi ", "Pian ", "Zong ", "Wan ", "Hui ", "Hou ", "He ", "He ", "Han ", "Ao ", "Piao ", "Yi ", "Lian ", "Qu ", "[?] ", "Lin ", "Pen ", "Qiao ", "Ao ", "Fan ", "Yi ", "Hui ", "Xuan ", "Dao " });

    this.characters.put(Integer.valueOf(128), new String[] { "Yao ", "Lao ", "[?] ", "Kao ", "Mao ", "Zhe ", "Qi ", "Gou ", "Gou ", "Gou ", "Die ", "Die ", "Er ", "Shua ", "Ruan ", "Er ", "Nai ", "Zhuan ", "Lei ", "Ting ", "Zi ", "Geng ", "Chao ", "Hao ", "Yun ", "Pa ", "Pi ", "Chi ", "Si ", "Chu ", "Jia ", "Ju ", "He ", "Chu ", "Lao ", "Lun ", "Ji ", "Tang ", "Ou ", "Lou ", "Nou ", "Gou ", "Pang ", "Ze ", "Lou ", "Ji ", "Lao ", "Huo ", "You ", "Mo ", "Huai ", "Er ", "Zhe ", "Ting ", "Ye ", "Da ", "Song ", "Qin ", "Yun ", "Chi ", "Dan ", "Dan ", "Hong ", "Geng ", "Zhi ", "[?] ", "Nie ", "Dan ", "Zhen ", "Che ", "Ling ", "Zheng ", "You ", "Wa ", "Liao ", "Long ", "Zhi ", "Ning ", "Tiao ", "Er ", "Ya ", "Die ", "Gua ", "[?] ", "Lian ", "Hao ", "Sheng ", "Lie ", "Pin ", "Jing ", "Ju ", "Bi ", "Di ", "Guo ", "Wen ", "Xu ", "Ping ", "Cong ", "Shikato ", "[?] ", "Ting ", "Yu ", "Cong ", "Kui ", "Tsuraneru ", "Kui ", "Cong ", "Lian ", "Weng ", "Kui ", "Lian ", "Lian ", "Cong ", "Ao ", "Sheng ", "Song ", "Ting ", "Kui ", "Nie ", "Zhi ", "Dan ", "Ning ", "Qie ", "Ji ", "Ting ", "Ting ", "Long ", "Yu ", "Yu ", "Zhao ", "Si ", "Su ", "Yi ", "Su ", "Si ", "Zhao ", "Zhao ", "Rou ", "Yi ", "Le ", "Ji ", "Qiu ", "Ken ", "Cao ", "Ge ", "Di ", "Huan ", "Huang ", "Yi ", "Ren ", "Xiao ", "Ru ", "Zhou ", "Yuan ", "Du ", "Gang ", "Rong ", "Gan ", "Cha ", "Wo ", "Chang ", "Gu ", "Zhi ", "Han ", "Fu ", "Fei ", "Fen ", "Pei ", "Pang ", "Jian ", "Fang ", "Zhun ", "You ", "Na ", "Hang ", "Ken ", "Ran ", "Gong ", "Yu ", "Wen ", "Yao ", "Jin ", "Pi ", "Qian ", "Xi ", "Xi ", "Fei ", "Ken ", "Jing ", "Tai ", "Shen ", "Zhong ", "Zhang ", "Xie ", "Shen ", "Wei ", "Zhou ", "Die ", "Dan ", "Fei ", "Ba ", "Bo ", "Qu ", "Tian ", "Bei ", "Gua ", "Tai ", "Zi ", "Ku ", "Zhi ", "Ni ", "Ping ", "Zi ", "Fu ", "Pang ", "Zhen ", "Xian ", "Zuo ", "Pei ", "Jia ", "Sheng ", "Zhi ", "Bao ", "Mu ", "Qu ", "Hu ", "Ke ", "Yi ", "Yin ", "Xu ", "Yang ", "Long ", "Dong ", "Ka ", "Lu ", "Jing ", "Nu ", "Yan ", "Pang ", "Kua ", "Yi ", "Guang ", "Gai ", "Ge ", "Dong ", "Zhi ", "Xiao ", "Xiong ", "Xiong ", "Er ", "E ", "Xing ", "Pian ", "Neng ", "Zi ", "Gui " });

    this.characters.put(Integer.valueOf(129), new String[] { "Cheng ", "Tiao ", "Zhi ", "Cui ", "Mei ", "Xie ", "Cui ", "Xie ", "Mo ", "Mai ", "Ji ", "Obiyaakasu ", "[?] ", "Kuai ", "Sa ", "Zang ", "Qi ", "Nao ", "Mi ", "Nong ", "Luan ", "Wan ", "Bo ", "Wen ", "Guan ", "Qiu ", "Jiao ", "Jing ", "Rou ", "Heng ", "Cuo ", "Lie ", "Shan ", "Ting ", "Mei ", "Chun ", "Shen ", "Xie ", "De ", "Zui ", "Cu ", "Xiu ", "Xin ", "Tuo ", "Pao ", "Cheng ", "Nei ", "Fu ", "Dou ", "Tuo ", "Niao ", "Noy ", "Pi ", "Gu ", "Gua ", "Li ", "Lian ", "Zhang ", "Cui ", "Jie ", "Liang ", "Zhou ", "Pi ", "Biao ", "Lun ", "Pian ", "Guo ", "Kui ", "Chui ", "Dan ", "Tian ", "Nei ", "Jing ", "Jie ", "La ", "Yi ", "An ", "Ren ", "Shen ", "Chuo ", "Fu ", "Fu ", "Ju ", "Fei ", "Qiang ", "Wan ", "Dong ", "Pi ", "Guo ", "Zong ", "Ding ", "Wu ", "Mei ", "Ruan ", "Zhuan ", "Zhi ", "Cou ", "Gua ", "Ou ", "Di ", "An ", "Xing ", "Nao ", "Yu ", "Chuan ", "Nan ", "Yun ", "Zhong ", "Rou ", "E ", "Sai ", "Tu ", "Yao ", "Jian ", "Wei ", "Jiao ", "Yu ", "Jia ", "Duan ", "Bi ", "Chang ", "Fu ", "Xian ", "Ni ", "Mian ", "Wa ", "Teng ", "Tui ", "Bang ", "Qian ", "Lu ", "Wa ", "Sou ", "Tang ", "Su ", "Zhui ", "Ge ", "Yi ", "Bo ", "Liao ", "Ji ", "Pi ", "Xie ", "Gao ", "Lu ", "Bin ", "Ou ", "Chang ", "Lu ", "Guo ", "Pang ", "Chuai ", "Piao ", "Jiang ", "Fu ", "Tang ", "Mo ", "Xi ", "Zhuan ", "Lu ", "Jiao ", "Ying ", "Lu ", "Zhi ", "Tara ", "Chun ", "Lian ", "Tong ", "Peng ", "Ni ", "Zha ", "Liao ", "Cui ", "Gui ", "Xiao ", "Teng ", "Fan ", "Zhi ", "Jiao ", "Shan ", "Wu ", "Cui ", "Run ", "Xiang ", "Sui ", "Fen ", "Ying ", "Tan ", "Zhua ", "Dan ", "Kuai ", "Nong ", "Tun ", "Lian ", "Bi ", "Yong ", "Jue ", "Chu ", "Yi ", "Juan ", "La ", "Lian ", "Sao ", "Tun ", "Gu ", "Qi ", "Cui ", "Bin ", "Xun ", "Ru ", "Huo ", "Zang ", "Xian ", "Biao ", "Xing ", "Kuan ", "La ", "Yan ", "Lu ", "Huo ", "Zang ", "Luo ", "Qu ", "Zang ", "Luan ", "Ni ", "Zang ", "Chen ", "Qian ", "Wo ", "Guang ", "Zang ", "Lin ", "Guang ", "Zi ", "Jiao ", "Nie ", "Chou ", "Ji ", "Gao ", "Chou ", "Mian ", "Nie ", "Zhi ", "Zhi ", "Ge ", "Jian ", "Die ", "Zhi ", "Xiu ", "Tai ", "Zhen ", "Jiu ", "Xian ", "Yu ", "Cha " });

    this.characters.put(Integer.valueOf(130), new String[] { "Yao ", "Yu ", "Chong ", "Xi ", "Xi ", "Jiu ", "Yu ", "Yu ", "Xing ", "Ju ", "Jiu ", "Xin ", "She ", "She ", "Yadoru ", "Jiu ", "Shi ", "Tan ", "Shu ", "Shi ", "Tian ", "Dan ", "Pu ", "Pu ", "Guan ", "Hua ", "Tan ", "Chuan ", "Shun ", "Xia ", "Wu ", "Zhou ", "Dao ", "Gang ", "Shan ", "Yi ", "[?] ", "Pa ", "Tai ", "Fan ", "Ban ", "Chuan ", "Hang ", "Fang ", "Ban ", "Que ", "Hesaki ", "Zhong ", "Jian ", "Cang ", "Ling ", "Zhu ", "Ze ", "Duo ", "Bo ", "Xian ", "Ge ", "Chuan ", "Jia ", "Lu ", "Hong ", "Pang ", "Xi ", "[?] ", "Fu ", "Zao ", "Feng ", "Li ", "Shao ", "Yu ", "Lang ", "Ting ", "[?] ", "Wei ", "Bo ", "Meng ", "Nian ", "Ju ", "Huang ", "Shou ", "Zong ", "Bian ", "Mao ", "Die ", "[?] ", "Bang ", "Cha ", "Yi ", "Sao ", "Cang ", "Cao ", "Lou ", "Dai ", "Sori ", "Yao ", "Tong ", "Yofune ", "Dang ", "Tan ", "Lu ", "Yi ", "Jie ", "Jian ", "Huo ", "Meng ", "Qi ", "Lu ", "Lu ", "Chan ", "Shuang ", "Gen ", "Liang ", "Jian ", "Jian ", "Se ", "Yan ", "Fu ", "Ping ", "Yan ", "Yan ", "Cao ", "Cao ", "Yi ", "Le ", "Ting ", "Qiu ", "Ai ", "Nai ", "Tiao ", "Jiao ", "Jie ", "Peng ", "Wan ", "Yi ", "Chai ", "Mian ", "Mie ", "Gan ", "Qian ", "Yu ", "Yu ", "Shuo ", "Qiong ", "Tu ", "Xia ", "Qi ", "Mang ", "Zi ", "Hui ", "Sui ", "Zhi ", "Xiang ", "Bi ", "Fu ", "Tun ", "Wei ", "Wu ", "Zhi ", "Qi ", "Shan ", "Wen ", "Qian ", "Ren ", "Fou ", "Kou ", "Jie ", "Lu ", "Xu ", "Ji ", "Qin ", "Qi ", "Yuan ", "Fen ", "Ba ", "Rui ", "Xin ", "Ji ", "Hua ", "Hua ", "Fang ", "Wu ", "Jue ", "Gou ", "Zhi ", "Yun ", "Qin ", "Ao ", "Chu ", "Mao ", "Ya ", "Fei ", "Reng ", "Hang ", "Cong ", "Yin ", "You ", "Bian ", "Yi ", "Susa ", "Wei ", "Li ", "Pi ", "E ", "Xian ", "Chang ", "Cang ", "Meng ", "Su ", "Yi ", "Yuan ", "Ran ", "Ling ", "Tai ", "Tiao ", "Di ", "Miao ", "Qiong ", "Li ", "Yong ", "Ke ", "Mu ", "Pei ", "Bao ", "Gou ", "Min ", "Yi ", "Yi ", "Ju ", "Pi ", "Ruo ", "Ku ", "Zhu ", "Ni ", "Bo ", "Bing ", "Shan ", "Qiu ", "Yao ", "Xian ", "Ben ", "Hong ", "Ying ", "Zha ", "Dong ", "Ju ", "Die ", "Nie ", "Gan ", "Hu ", "Ping ", "Mei ", "Fu ", "Sheng ", "Gu ", "Bi ", "Wei " });
  }
}