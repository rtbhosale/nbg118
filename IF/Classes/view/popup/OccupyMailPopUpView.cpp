//
//  OccupyMailPopUpView.cpp
//  IF
//
//  Created by 李锐奇 on 14-4-16.
//
//

#include "OccupyMailPopUpView.h"
#include "PopupViewController.h"
#include "MailController.h"
#include "RewardController.h"
#include "MailPopUpView.h"
#include "GeneralHeadPic.h"
#include "WorldController.h"
#include "SceneController.h"
#include "WorldMapView.h"
#include "YesNoDialog.h"
#include "MailSaveCommand.h"
#include "ChatServiceCocos2dx.h"
#include "MailWritePopUpView.h"
#include "UIComponent.h"
//#include "SoldierIconCell.hpp"
#include "ArmyController.h"
OccupyMailPopUpView *OccupyMailPopUpView::create(MailInfo *info){
    OccupyMailPopUpView *ret = new OccupyMailPopUpView(info);
    if(ret && ret->init()){
        ret->autorelease();
    }else{
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

void OccupyMailPopUpView::onEnter(){
    PopupBaseView::onEnter();
    UIComponent::getInstance()->showPopupView(UIPopupViewType_ArcPop_TitanUpgrade,true);//simon;
    UIComponent::getInstance()->hideReturnBtn();
    CCSafeNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(OccupyMailPopUpView::refresh), MAIL_CONTENT_READ, NULL);
//    setTitleName(m_info->fromName.c_str());
    m_mailTitle->setString(m_info->fromName.c_str());
    setTouchEnabled(true);
    
}

void OccupyMailPopUpView::onExit(){
    CCSafeNotificationCenter::sharedNotificationCenter()->removeObserver(this, MAIL_CONTENT_READ);
   setTouchEnabled(false);
    PopupBaseView::onExit();
}

bool OccupyMailPopUpView::init(){
    bool ret = false;
    if(PopupBaseView::init()){
        setIsHDPanel(true);
        setMailUuid(m_info->uid);
//        auto cf = CCLoadSprite::getSF("Mail_diban.png");
        auto cf = CCLoadSprite::getSF("Mail_BG1.png");
        if (cf==NULL) {
            CCLoadSprite::doResourceByCommonIndex(6, true);
            CCLoadSprite::doResourceByCommonIndex(204, true);
            setCleanFunction([](){
                CCLoadSprite::doResourceByCommonIndex(6, false);
                CCLoadSprite::doResourceByCommonIndex(204, false);
            });
        }
        else {
            CCLoadSprite::doResourceByCommonIndex(204, true);
            setCleanFunction([](){
                CCLoadSprite::doResourceByCommonIndex(204, false);
            });
        }
        auto bg = CCBLoadFile("NEW_OccupyMailCCB", this, this);
        if (CCCommonUtils::isIosAndroidPad()) {
            this->setContentSize(CCDirector::sharedDirector()->getWinSize());
        }
        else
            this->setContentSize(bg->getContentSize());

        m_listNode = CCNode::create();
//        setTitleName(_lang("105513"));
        this->m_titleText->setFntFile("Arial_Bold_Regular.fnt");
        this->m_timeText->setFntFile("Arial_Bold_Regular.fnt");
        this->m_armsName->setFntFile("Arial_Bold_Regular.fnt");
        this->m_armsNun->setFntFile("Arial_Bold_Regular.fnt");
        this->m_failText->setFntFile("Arial_Bold_Regular.fnt");
        m_mailTitle->setString(_lang("105513"));
        this->m_timeText->setString(CCCommonUtils::timeStampToDate(m_info->createTime).c_str());
        m_titleText->setString(_lang("105536").c_str());
        //m_contentText ->setString(_lang("105537").c_str());
        std::string picUrl = "";
        string  description1 = "";
        switch (m_info->pointType) {
            case Throne:{
                picUrl = "Mail_darksoil.png";
                description1 = _lang("105712");
                break;
            }
            case Trebuchet:{
                picUrl = "Mail_darksoil.png";
                description1 = _lang("105713");
                break;
            }
            default:{
                if(m_info->isTreasureMap){
                    picUrl = "Mail_zhaying_succeed.png";
                    description1 = _lang_3("111506", "","","");
                }else{
                    picUrl = "Mail_zhaying_succeed.png";
                    description1 = _lang_1("105538", "");
                }
                break;
            }
        }
//        m_occupyText->setString(description1);
        if (CCCommonUtils::isIosAndroidPad()) {
            int extH = getExtendHeight();
            this->m_listContainer->setContentSize(CCSize(m_listContainer->getContentSize().width, m_listContainer->getContentSize().height + extH));
            m_downNode->setPositionY(m_downNode->getPositionY() - extH);
            m_bgNode->setPositionY(m_bgNode->getPositionY() - extH);
            auto tbg = CCLoadSprite::loadResource("Mail_diban.png");
            auto tBatchNode = CCSpriteBatchNode::createWithTexture(tbg->getTexture());
            auto picBg1 = CCLoadSprite::createSprite("Mail_diban.png");
            picBg1->setAnchorPoint(ccp(0, 0));
            picBg1->setPosition(ccp(0, 0));
            picBg1->setScaleX(2.4);
            tBatchNode->addChild(picBg1);
            int maxHeight = CCDirector::sharedDirector()->getWinSize().height;
            int curHeight = picBg1->getContentSize().height;
            while(curHeight < maxHeight)
            {
                auto picBg2 = CCLoadSprite::createSprite("Mail_diban.png");
                picBg2->setAnchorPoint(ccp(0, 0));
                picBg2->setPosition(ccp(0, curHeight));
                picBg2->setScaleX(2.4);
                tBatchNode->addChild(picBg2);
                curHeight += picBg2->getContentSize().height;
            }
            m_bgNode->addChild(tBatchNode);
        }
        else {
            int extH = getExtendHeight();
            this->m_listContainer->setContentSize(CCSize(m_listContainer->getContentSize().width, m_listContainer->getContentSize().height + extH));
            m_downNode->setPositionY(m_downNode->getPositionY() - extH);
            m_bgNode->setPositionY(m_bgNode->getPositionY() - extH);
            auto tbg = CCLoadSprite::loadResource("Mail_diban.png");
            auto tBatchNode = CCSpriteBatchNode::createWithTexture(tbg->getTexture());
            auto picBg1 = CCLoadSprite::createSprite("Mail_diban.png");
            picBg1->setAnchorPoint(ccp(0, 0));
            picBg1->setPosition(ccp(0, 0));
            tBatchNode->addChild(picBg1);
            int maxHeight = CCDirector::sharedDirector()->getWinSize().height;
            int curHeight = picBg1->getContentSize().height;
            while(curHeight < maxHeight)
            {
                auto picBg2 = CCLoadSprite::createSprite("Mail_diban.png");
                picBg2->setAnchorPoint(ccp(0, 0));
                picBg2->setPosition(ccp(0, curHeight));
                tBatchNode->addChild(picBg2);
                curHeight += picBg2->getContentSize().height;
            }
            m_bgNode->addChild(tBatchNode);
        }

//        this->m_bg->setContentSize(CCSize(m_bg->getContentSize().width, m_bg->getContentSize().height + dh));
        
       // m_listContainer->setVisible(false);//暂时隐掉，现在没有英雄
        
//        CCSize size = m_paneBg->getContentSize();
//        m_paneBg->setContentSize(CCSize(size.width, size.height + dh));
//        
//        CCSize size2 = m_paneBg->getContentSize();
        m_scrollView = CCScrollView::create(m_listContainer->getContentSize());
        m_scrollView->setDirection(kCCScrollViewDirectionVertical);
        m_scrollView->setAnchorPoint(ccp(0, 0));
        m_listContainer->addChild(m_scrollView);
        /////////////
        m_battlePicNode->removeAllChildrenWithCleanup(true);
        auto battlePic = CCLoadSprite::createSprite(picUrl.c_str());
        this->m_battlePicNode->addChild(battlePic);
       // m_tabView = NULL;
        this->m_totalNode->removeChild(this->m_moveNode);
        m_scrollView->addChild(m_listNode);
        
        m_totalHg = 0;
//        m_totalHg -= 666;
        m_listNode->addChild(m_moveNode);
        if (CCCommonUtils::isIosAndroidPad()) {
            m_moveNode->setPosition(768,m_totalHg);
        }
        else {
            m_moveNode->setPosition(320,m_totalHg);
        }
        m_headImgNode = HFHeadImgNode::create();
        if (CCCommonUtils::isIosAndroidPad()) {
            m_totalHg -= 874;
        }
        else
            m_totalHg -= 364;
        if(!m_info->isReadContent){
            getData();
        }else{
            refresh(NULL);
            this->m_listNode->setPositionY(-m_totalHg);
            m_scrollView->setContentSize(CCSize(m_listContainer->getContentSize().width, -m_totalHg));
            m_scrollView->setContentOffset(ccp(0, m_listContainer->getContentSize().height - (-m_totalHg)));
        }
        ret = true;
    }
    return ret;
}

void OccupyMailPopUpView::onBtnPosClick(CCObject *pSender, CCControlEvent event){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    ChatServiceCocos2dx::stopReturnToChat();
#elif(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//simon    ChatServiceCocos2dx::stopReturnToChat();
#endif
    int pos = m_info->occupyPointId;
    WorldController::getInstance()->openTargetIndex = pos;
    CCPoint pt = WorldController::getPointByIndex(pos);
//    if (m_info && m_info->serverType>=SERVER_BATTLE_FIELD) {
//        pt = WorldController::getPointByMapTypeAndIndex(pos,(MapType)m_info->serverType);
//    } simon
    if(SceneController::getInstance()->currentSceneId == SCENE_ID_WORLD){
        WorldMapView::instance()->gotoTilePoint(pt);
    }else{
        int index = WorldController::getIndexByPoint(pt);
        SceneController::getInstance()->gotoScene(SCENE_ID_WORLD, false, true, index);
    }
    //zym 2015.12.11
//    PopupViewController::getInstance()->forceClearAll(true); simon
    PopupViewController::getInstance()->removeAllPopupView();
}
bool OccupyMailPopUpView::onTouchBegan(CCTouch *pTouch, CCEvent *pEvent){
    if (isTouchInside(m_returnSpr, pTouch)) {
        return true;
    }
    return false;
}
void OccupyMailPopUpView::onTouchMoved(CCTouch *pTouch, CCEvent *pEvent){
    
}
void OccupyMailPopUpView::onTouchEnded(CCTouch *pTouch, CCEvent *pEvent){
    if (isTouchInside(m_returnSpr, pTouch)) {
        PopupViewController::getInstance()->goBackPopupView();
    }
}
bool OccupyMailPopUpView::onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode){
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_titleText", CCLabelIF*, this->m_titleText);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this, "m_mailTitle", CCLabelIF*, this->m_mailTitle);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_contentText", CCLabelIF*, this->m_contentText);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_timeText", CCLabelIF*, this->m_timeText);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_occupyText", CCLabelIF*, this->m_occupyText);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_listContainer", CCNode*, this->m_listContainer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_failNode", CCNode*, this->m_failNode);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_downNode", CCNode*, this->m_downNode);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this, "m_bgNode", CCNode*, this->m_bgNode);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_bg", CCScale9Sprite*, this->m_bg);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_buildBG", CCScale9Sprite*, this->m_buildBG);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this, "m_deleteBtn", CCControlButton*, this->m_deleteBtn);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this, "m_unSaveBtn", CCControlButton*, this->m_unSaveBtn);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this, "m_addSaveBtn", CCControlButton*, this->m_addSaveBtn);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this, "m_writeBtn", CCControlButton*, this->m_writeBtn);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this, "m_returnBtn", CCControlButton*, this->m_returnBtn);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this, "m_returnSpr", CCSprite*, this->m_returnSpr);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_paneBg", CCScale9Sprite*, this->m_paneBg)
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_palyName", Label*, this->m_palyName);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_playLv", CCLabelIF*, this->m_playLv);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_failText", CCLabelIF*, this->m_failText);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_picHeadNode", CCNode*, this->m_picHeadNode);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_playerNode", CCNode*, this->m_playerNode);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_listBG", CCScale9Sprite*, this->m_listBG);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_kuangBG", CCScale9Sprite*, this->m_kuangBG);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_totalNode", CCNode*, this->m_totalNode);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_moveNode", CCNode*, this->m_moveNode);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_armsNun", CCLabelIF*, this->m_armsNun);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_armsName", CCLabelIF*, this->m_armsName);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_armsListNode", CCNode*, this->m_armsListNode);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_battlePicNode", CCNode*, this->m_battlePicNode);
    return false;
}

void OccupyMailPopUpView::onDeleteClick(CCObject *pSender, CCControlEvent event){
    if(m_info->save!=0){
        CCCommonUtils::flyHint("","",_lang("105575"));
        return;
    }
    YesNoDialog::showYesDialog(_lang("105570").c_str(),false,CCCallFunc::create(this, callfunc_selector(OccupyMailPopUpView::onOKDeleteMail)),true);

}
void OccupyMailPopUpView::onReturnClick(cocos2d::CCObject *pSender, CCControlEvent pCCControlEvent){
    PopupViewController::getInstance()->goBackPopupView();
}

void OccupyMailPopUpView::onWriteClick(cocos2d::CCObject *pSender, CCControlEvent pCCControlEvent){
    PopupViewController::getInstance()->addPopupInView(MailWritePopUpView::create("", ""));
}
void OccupyMailPopUpView::onAddSaveClick(CCObject *pSender, CCControlEvent event){
    if(m_info->save ==1){
        MailCancelSaveCommand *cmd = new MailCancelSaveCommand(m_info->uid, m_info->type);
        cmd->sendAndRelease();
        m_info->save = 0;
        CCCommonUtils::flyHint("quest_icon_1.png", "", _lang("105576"));
    }else{
        if(MailController::getInstance()->isMailFull(SAVEMAIL)){
            CCCommonUtils::flyText("full");
            return;
        }
        MailSaveCommand *cmd = new MailSaveCommand(m_info->uid, m_info->type);
        cmd->sendAndRelease();
        m_info->save = 1;
        CCCommonUtils::flyHint("quest_icon_1.png", "", _lang("105575"));
    }
    if(m_info->save==0){
        m_addSaveBtn->setHighlighted(false);
    }else{
        m_addSaveBtn->setHighlighted(true);
    }
}
void OccupyMailPopUpView::onOKDeleteMail(){
    MailController::getInstance()->removeMail(m_info->uid, CC_ITOA(m_info->type));
    PopupViewController::getInstance()->goBackPopupView();

}
SEL_CCControlHandler OccupyMailPopUpView::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName){
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onDeleteClick", OccupyMailPopUpView::onDeleteClick);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onBtnPosClick", OccupyMailPopUpView::onBtnPosClick);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onAddSaveClick", OccupyMailPopUpView::onAddSaveClick);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onReturnClick", OccupyMailPopUpView::onReturnClick);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onWriteClick", OccupyMailPopUpView::onWriteClick);
    return NULL;
}

void OccupyMailPopUpView::gridTouched(cocos2d::extension::CCMultiColTableView* table, CCTableViewCell* cell){
}

cocos2d::CCSize OccupyMailPopUpView::gridSizeForTable(cocos2d::extension::CCMultiColTableView *table){
    return CCSize(200, 160);
}

CCTableViewCell* OccupyMailPopUpView::gridAtIndex(cocos2d::extension::CCMultiColTableView *table, unsigned int idx){
    if(idx >= m_info->occupyGeneral->count()){
        return NULL;
    }
    CCDictionary *dict = dynamic_cast<CCDictionary*>(m_info->occupyGeneral->objectAtIndex(idx));
    OccupyMailGeneralCell* cell = (OccupyMailGeneralCell*)table->dequeueGrid();
    std::string generalId = dict->valueForKey("genId")->getCString();
    int level = dict->valueForKey("level")->intValue();
    int color = dict->valueForKey("color")->intValue();
    int num = dict->valueForKey("armyNum")->intValue();
    if(idx < m_info->occupyGeneral->count()){
        if(cell){
            cell->setData(generalId, num, color, level);
        }else{
            cell = OccupyMailGeneralCell::create(generalId, num, color, level);
        }
    }
    return cell;
}

ssize_t OccupyMailPopUpView::numberOfCellsInTableView(cocos2d::extension::CCMultiColTableView *table){
    if(m_info->occupyGeneral == NULL){
        return 0;
    }
    int num = ceil(m_info->occupyGeneral->count() / 2.0);
    return num;
}

unsigned int OccupyMailPopUpView::numberOfGridsInCell(cocos2d::extension::CCMultiColTableView *multiTable){
    return 2;
}

void OccupyMailPopUpView::refresh(CCObject* p){
    if(m_info->save==0){
        m_addSaveBtn->setHighlighted(false);
    }else{
        m_addSaveBtn->setHighlighted(true);
    }
//    if(m_tabView == NULL
//        m_tabView = CCMultiColTableView::create(this, m_listContainer->getContentSize());
//        m_tabView->setDirection(kCCScrollViewDirectionVertical);
//        m_tabView->setVerticalFillOrder(kCCTableViewFillTopDown);
//        m_tabView->setMultiColTableViewDelegate(this);
//        m_tabView->setTouchPriority(1);
//        m_listContainer->addChild(m_tabView);
//    }
//    m_tabView->setTouchEnabled(158*m_info->occupyGeneral->count()>m_listContainer->getContentSize().height);
//    m_tabView->reloadData();
    CCPoint pt = WorldController::getPointByIndex(m_info->occupyPointId);
//    if (m_info && m_info->serverType>=SERVER_BATTLE_FIELD) {
//        pt = WorldController::getPointByMapTypeAndIndex(m_info->occupyPointId,(MapType)m_info->serverType);
//    } simon
    //this->m_occupyText->setString(_lang_2("105521", CC_ITOA(int(pt.x)),CC_ITOA(int(pt.y))));
    this->m_kuangBG->setVisible(false);
    string  description1 = "";
    bool bTroop = true;
    switch (m_info->pointType) {
        case Throne:{
            description1 = _lang("105712");
            bTroop = false;
            break;
        }
        case Trebuchet:{
            description1 = _lang("105713");
            bTroop = false;
            break;
        }
        default:{
            if(m_info->isTreasureMap){
                description1 = _lang_3("111506",  "",CC_ITOA(int(pt.x)),CC_ITOA(int(pt.y)));
            }else{
                description1 = _lang_3("105538","",CC_ITOA(int(pt.x)),CC_ITOA(int(pt.y)));
            }
            break;
        }
    }
//    m_occupyText->setString(description1);
    int startY = 0;
    if(m_info->user!=NULL){
        std::string name = m_info->user->valueForKey("name")->getCString();
        int level = m_info->user->valueForKey("lv")->intValue();
        std::string levelStr = std::string("Lv.") +CC_ITOA(level);
//        this->m_playLv->setString(levelStr.c_str());
        name.append(" ").append("Lv.").append(CC_ITOA(level));
        this->m_palyName->setString(name.c_str());
        string pic =m_info->user->valueForKey("pic")->getCString();
        int picVer = m_info->user->valueForKey("picVer")->intValue();
        string uid = m_info->user->valueForKey("uid")->getCString();
        if(pic==""){
            pic = "g044.png";
        }else{
            pic +=".png";
        }
        auto head = CCLoadSprite::createSprite(pic.c_str());
        float scale = 70/head->getContentSize().width;
        if(scale>1.0){
            scale = 1.0;
        }
        head->setScale(scale);
//        this->m_picHeadNode->addChild(head);
//        if (CCCommonUtils::isUseCustomPic(picVer))
//        {
//            m_headImgNode->initHeadImgUrl2(m_picHeadNode, CCCommonUtils::getCustomPicUrl(uid, picVer), 1.0f, 70, true);
//        }
        m_playerNode->setVisible(true);
        
        ////////融合底图
        auto sizeLayer = CCSize(80, 80);
        m_selfModelLayer = CCRenderTexture::create(sizeLayer.width, sizeLayer.height);
        m_selfModelLayer->setAnchorPoint(ccp(0.5, 0.5));
        ccBlendFunc cbf = {GL_ZERO,GL_ONE_MINUS_SRC_ALPHA};
        auto spr = CCLoadSprite::createSprite("Mail_headBack.png");
        spr->setScale(1);
        spr->setPosition(ccp(sizeLayer.width / 2, sizeLayer.height / 2));
        auto bgCircle = CCLoadSprite::createSprite("Mail_head_backBattle.png");
        bgCircle->setBlendFunc(cbf);
        bgCircle->setPosition(ccp(sizeLayer.width / 2, sizeLayer.height / 2));
        head->setPosition(ccp(sizeLayer.width / 2, sizeLayer.height / 2 - 3));
        //    pic->removeFromParent();
        m_selfModelLayer->begin();
        spr->visit();
        head->visit();
        bgCircle->visit();
        m_selfModelLayer->end();
        m_playerNode->addChild(m_selfModelLayer);
        if (CCCommonUtils::isUseCustomPic(picVer) && uid != "")
        {
            string backImg = "Mail_headBack.png";
            string renderImg = "Mail_head_backBattle.png";
//            m_headImgNode->initHeadImgUrl3(m_playerNode, CCCommonUtils::getCustomPicUrl(uid, picVer), 1.0f, 74, true, ccp(sizeLayer.width / 2, sizeLayer.height / 2 - 2), sizeLayer, backImg, renderImg);
        }
    }else{
        m_playerNode->setVisible(false);
        startY = 100;
    }
    
    if(m_info->occupyGeneral==NULL || bTroop==false){
        this->m_failNode->setVisible(false);
        this->m_kuangBG->setVisible(false);
        this->m_armsName->setString("");
        this->m_armsNun->setString("");
//        this->m_listBG->setContentSize(CCSize(m_listBG->getContentSize().width,430));
    }else{
        if(m_info->occupyGeneral->count()>0){
            m_totalHg -= startY;
            CCDictionary *dict = dynamic_cast<CCDictionary*>(m_info->occupyGeneral->objectAtIndex(0));
            this->m_failNode->setVisible(false);
            //m_picHeadNode->setVisible(false);
            this->m_armsName->setString(_lang("108557"));
            this->m_armsNun->setString(_lang("105558"));
            this->m_kuangBG->setVisible(true);
            this->m_kuangBG->setPositionY(this->m_kuangBG->getPositionY()+startY);
            this->m_armsName->setPositionY(this->m_armsName->getPositionY()+startY);
            this->m_armsNun->setPositionY(this->m_armsNun->getPositionY()+startY);
            this->m_armsListNode->setPositionY(this->m_armsListNode->getPositionY()+startY);
            
            CCObject *obj = NULL;
            int i = 0;
            int posX = 0;
            CCARRAY_FOREACH(m_info->occupyGeneral, obj){
                CCDictionary *reward = dynamic_cast<CCDictionary*>(obj);
                string id = reward->valueForKey("armyId")->getCString();
                string armname =CCCommonUtils::getNameById(id);
                int num = atoi(reward->valueForKey("armyNum")->getCString());
                
                auto cell = DetectArmyCell::create(id, num,false,true);
                cell->setAnchorPoint(ccp(0, 0));
                if (CCCommonUtils::isIosAndroidPad()) {
                    cell->setPosition(ccp(posX, 0-i*264));
                }
                else
                    cell->setPosition(ccp(posX,  0-i*110));
                m_armsListNode->addChild(cell);
                i++;
            }
            if (CCCommonUtils::isIosAndroidPad()) {
                m_totalHg -= 432;
            }
            else
                m_totalHg -= 180;
            if(i>1){
                if (CCCommonUtils::isIosAndroidPad()) {
                    m_kuangBG->setContentSize(CCSize(m_kuangBG->getContentSize().width, m_kuangBG->getContentSize().height+(i-1)*264));
                    m_totalHg-=(i-1)*264;
                }
                else {
                    m_kuangBG->setContentSize(CCSize(m_kuangBG->getContentSize().width, m_kuangBG->getContentSize().height+(i-1)*110));
                    m_totalHg-=(i-1)*110;
                }
            }
            if (CCCommonUtils::isIosAndroidPad()) {
                m_totalHg -= 48;
            }
            else
                m_totalHg -= 20;
        }else if(m_info->user==NULL){
            this->m_kuangBG->setVisible(false);
            this->m_failNode->setVisible(true);
            this->m_failText->setString(_lang("114009"));
//            m_occupyText->setString(_lang("105588"));
        }
    }
}

void OccupyMailPopUpView::getData(){
    MailController::getInstance()->readMailFromServer(m_info->uid, CC_ITOA(m_info->type));
}

//-----------

OccupyMailGeneralCell *OccupyMailGeneralCell::create(std::string generalId, int num, int color, int level){
    OccupyMailGeneralCell *ret = new OccupyMailGeneralCell(generalId, num, color, level);
    if(ret && ret->init()){
        ret->autorelease();
    }else{
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

void OccupyMailGeneralCell::setData(std::string generalId, int num, int color, int level){
    m_generalId = generalId;
    m_num = num;
    m_level = level;
    m_color = color;
    refreshView();
}

bool OccupyMailGeneralCell::init(){
    auto bg = CCBLoadFile("OccupyMailGeneralCCB", this, this);
    this->setContentSize(bg->getContentSize());
    refreshView();
    return true;
}

void OccupyMailGeneralCell::refreshView(){
    this->m_nameText->setString(CCCommonUtils::getNameById(m_generalId).c_str());
    std::string levelStr = _lang_1("103462", CC_ITOA(m_level));
    this->m_lvText->setString(levelStr);
    this->m_numText->setString(CC_CMDITOA(m_num));

    //this->m_nameText->setColor(CCCommonUtils::getItemColor(m_color));
    this->m_lvText->setColor(ccWHITE);//CCCommonUtils::getItemColor(m_color)
    auto head = GeneralHeadPic::create(m_generalId, m_color);
    this->m_headContainer->removeAllChildren();
    this->m_headContainer->addChild(head);
}

bool OccupyMailGeneralCell::onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode){
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_nameText", CCLabelIF*, this->m_nameText);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_lvText", CCLabelIF*, this->m_lvText);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_numText", CCLabelIF*, this->m_numText);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_headContainer", CCNode*, this->m_headContainer);
    
    return false;
}

OccupyLossPreviewCell *OccupyLossPreviewCell::create(string type, int num, bool b){
    OccupyLossPreviewCell *ret = new OccupyLossPreviewCell(type, num, b);
    if(ret && ret->init()){
        ret->autorelease();
    }else{
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

void OccupyLossPreviewCell::setData(string type, int num, bool b){
    m_type = type;
    m_num = num;
    m_about = b;
    refreshView();
}

bool OccupyLossPreviewCell::init(){
    refreshView();
    
    return true;
}

void OccupyLossPreviewCell::refreshView(){
    this->removeAllChildren();
    auto label = CCLabelIF::create();
    label->setFntFile("Arial_Bold_Regular.fnt");
    label->setFontSize(22);
    label->setColor(ccc3(130, 99, 56));
    label->setString(m_type.c_str());
    label->setAnchorPoint(ccp(0, 0.5));
    //int width =bg->getContentSize().width/2;
    if (CCCommonUtils::isIosAndroidPad()) {
        label->setFontSize(44);
        label->setPosition(40,0);
    }
    else
        label->setPosition(20, 0);
    this->addChild(label);
    
    std::string numstr = "";
    if(m_about){
        numstr = "~";
    }
    numstr.append(CC_CMDITOA(m_num));
    auto label1 = CCLabelIF::create();
    label1->setFntFile("Arial_Bold_Regular.fnt");
    label1->setFontSize(22);
    label1->setColor(ccc3(127, 35, 29));
    label1->setString(numstr.c_str());
    label1->setAnchorPoint(ccp(0, 0.5));
    if (CCCommonUtils::isIosAndroidPad()) {
        label1->setFontSize(44);
        label1->setPosition(900, 0);
    }
    else
        label1->setPosition(435, 0);
    this->addChild(label1);
}

//
DetectArmyCell *DetectArmyCell::create(string armId,int num,bool isAbout,bool bself){
    DetectArmyCell *ret = new DetectArmyCell(armId,num,isAbout,bself);
    if(ret && ret->init()){
        ret->autorelease();
    }else{
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

void DetectArmyCell::setData(string armId,int num,bool isAbout,bool bself){
    m_armId = armId;
    m_num = num;
    m_isAbout =isAbout;
    m_self = bself;
    refreshView();
}

bool DetectArmyCell::init(){
    auto bg = CCBLoadFile("NEW_DetectMailNewView", this, this);// 110 height
    refreshView();
    
    return true;
}
bool DetectArmyCell::onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode){

    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_levelNode", CCNode*, this->m_levelNode);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_headPicNode", CCNode*, this->m_headPicNode);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_nunText", CCLabelIF*, this->m_nunText);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this,"m_nameText", CCLabelIF*, this->m_nameText);
    return false;
}
void DetectArmyCell::refreshView(){
    m_nameText->setFntFile("Arial_Bold_Regular.fnt");
    m_nunText->setFntFile("Arial_Bold_Regular.fnt");
    if(m_num>=0){
        std::string numstr = "";
        if(m_isAbout){
            numstr = "~";
        }
        numstr.append(CC_CMDITOA(m_num));
        this->m_nunText->setString(numstr);
    }else{
        this->m_nunText->setString("");
    }
    std::string icon = GlobalData::shared()->armyList[m_armId].getHeadIcon();
//    auto pic1  = CCLoadSprite::createSprite(icon.c_str());
//    m_headPicNode->addChild(pic1,0);
//    CCCommonUtils::setSpriteMaxSize(pic1, 132);
//    SoldierIconCell* pic1;
//    if(!m_self){
//        pic1 = SoldierIconCell::create(icon.c_str(), 132,m_armId,false,0);
//    }else{
//        int star = ArmyController::getInstance()->getStarlvById(m_armId);
//        pic1 = SoldierIconCell::create(icon.c_str(), 132,m_armId,true,star);
//    }
//    if(pic1 != nullptr){
//        m_headPicNode->addChild(pic1,0);
//    } simon
    string path = m_armId.substr(m_armId.size()-2);
    int num  = atoi(path.c_str())+1;
    path = "Roman_";
    path.append(CC_ITOA(num));
    path.append(".png");
    auto pic  = CCLoadSprite::createSprite(path.c_str());
    m_levelNode->addChild(pic);
    CCCommonUtils::setSpriteMaxSize(pic, 90);
    string name  = CCCommonUtils::getNameById(m_armId);
    m_nameText->setString(name);
    //this->addChild(label1);
}
