package com.elex.chatservice.model.mail.detectreport;

import java.util.List;

public class DefenceParams {
//	"defence":{"total":220,"about":false,"arms":[{"id":"107001","num":220}]},
	private int total;
	private boolean about;
	private List<ArmsParams> arms;
	public int getTotal() {
		return total;
	}
	public void setTotal(int total) {
		this.total = total;
	}
	public boolean isAbout() {
		return about;
	}
	public void setAbout(boolean about) {
		this.about = about;
	}
	public List<ArmsParams> getArms() {
		return arms;
	}
	public void setArms(List<ArmsParams> arms) {
		this.arms = arms;
	}
	
	
}
