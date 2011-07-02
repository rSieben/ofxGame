/*
 *  ofxCharProxy.h
 *  pakapakaPulido
 *
 *  Created by Patricio González Vivo on 30/06/11.
 *  Copyright 2011 PatricioGonzalezVivo.com. All rights reserved.
 *
 */

#ifndef OFXCHARPROXY
#define OFXCHARPROXY

#include "ofxObject.h"
#include "ofxCharacter.h"

class ofxCharProxy : public ofxGameObj {
public:
	ofxCharProxy(){
		objectName = "character"; 
		loadXml();
		character.load(file);
		reset();
		saveXml();
	}
	
	void	reset(){
		width = character.getWidth();
		height = character.getHeight();
		character.setScale(scale);
		character.pos.set(x, y);
	}
	
	void	update(){
		character.update();
	}

	void	draw(){ 
		character.setScale(scale);
		character.pos.set(x, y);
		draw(x,y);
	};	
	void	draw(int _x, int _y){
		ofSetColor(255, 255);
		character.draw(*bDebug);
		
		ofPushMatrix();
		ofTranslate(_x-width*0.5,_y-height*0.5);
		ofScale(scale, scale);
		if (*bDebug){
			ofSetColor(255, 255);
			ofLine(0,0, 0, height);
			ofLine(0,0, width, 0);
			ofLine(width,0, 0, 0);
			ofLine(0,height, 0, 0);
			ofLine(0,height,width,height);
			ofLine(0, 0, width, height);
			ofLine(width,0,0,height);
			ofSetColor(255, 255);
		}
		
		ofPopMatrix();
	};
	
	ofxCharacter * getCharacter(){return & character;};
private:
	ofxCharacter	character;
};
#endif