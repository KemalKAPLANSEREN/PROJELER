/*
	 * Created by SharpDevelop.
	 * User: m_pek
	 * Date: 12/18/2024
	 * Time: 1:16 AM
	 * 
	 * To change this template use Tools | Options | Coding | Edit Standard Headers.
	 */
	namespace LCDSeriPortson
	{
		partial class MainForm
		{
			/// <summary>
			/// Designer variable used to keep track of non-visual components.
			/// </summary>
			private System.ComponentModel.IContainer components = null;
			private System.Windows.Forms.Label label1;
			private System.Windows.Forms.Button baslangicDegerGonder;
			private System.Windows.Forms.TextBox zamanTextBox2;
			private System.Windows.Forms.Label label2;
			private System.Windows.Forms.Button SaatAl;
			private System.Windows.Forms.TextBox zamanTextBox;
			private System.IO.Ports.SerialPort serialPort1;
			private System.Windows.Forms.TextBox textBoudrate;
			private System.Windows.Forms.Label label3;
			private System.Windows.Forms.TextBox textcom;
			private System.Windows.Forms.Label label4;
			private System.Windows.Forms.TextBox textdatabits;
			private System.Windows.Forms.Label label5;
			private System.Windows.Forms.Button btnac;
			private System.Windows.Forms.Button btnkpt;
			private System.Windows.Forms.TextBox textadc;
			private System.Windows.Forms.Label label6;
			private System.Windows.Forms.TextBox textBox1;
			private System.Windows.Forms.Label textgelenveriler;
			private System.Windows.Forms.Button btngonder;
			private System.Windows.Forms.TextBox textgonderilecekveriler;
			private System.Windows.Forms.Label label7;
			private System.Windows.Forms.Button btnsicaklik;
			
			/// <summary>
			/// Disposes resources used by the form.
			/// </summary>
			/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
			protected override void Dispose(bool disposing)
			{
				if (disposing) {
					if (components != null) {
						components.Dispose();
					}
				}
				base.Dispose(disposing);
			}
			
			/// <summary>
			/// This method is required for Windows Forms designer support.
			/// Do not change the method contents inside the source code editor. The Forms designer might
			/// not be able to load this method if it was changed manually.
			/// </summary>
			private void InitializeComponent()
			{
				this.components = new System.ComponentModel.Container();
				this.label1 = new System.Windows.Forms.Label();
				this.zamanTextBox = new System.Windows.Forms.TextBox();
				this.baslangicDegerGonder = new System.Windows.Forms.Button();
				this.zamanTextBox2 = new System.Windows.Forms.TextBox();
				this.label2 = new System.Windows.Forms.Label();
				this.SaatAl = new System.Windows.Forms.Button();
				this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
				this.textBoudrate = new System.Windows.Forms.TextBox();
				this.label3 = new System.Windows.Forms.Label();
				this.textcom = new System.Windows.Forms.TextBox();
				this.label4 = new System.Windows.Forms.Label();
				this.textdatabits = new System.Windows.Forms.TextBox();
				this.label5 = new System.Windows.Forms.Label();
				this.btnac = new System.Windows.Forms.Button();
				this.btnkpt = new System.Windows.Forms.Button();
				this.textadc = new System.Windows.Forms.TextBox();
				this.label6 = new System.Windows.Forms.Label();
				this.textBox1 = new System.Windows.Forms.TextBox();
				this.textgelenveriler = new System.Windows.Forms.Label();
				this.btngonder = new System.Windows.Forms.Button();
				this.textgonderilecekveriler = new System.Windows.Forms.TextBox();
				this.label7 = new System.Windows.Forms.Label();
				this.btnsicaklik = new System.Windows.Forms.Button();
				this.SuspendLayout();
				// 
				// label1
				// 
				this.label1.Location = new System.Drawing.Point(65, 491);
				this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
				this.label1.Name = "label1";
				this.label1.Size = new System.Drawing.Size(144, 21);
				this.label1.TabIndex = 0;
				this.label1.Text = "Gönderilecek Saat";
				// 
				// zamanTextBox
				// 
				this.zamanTextBox.Location = new System.Drawing.Point(235, 491);
				this.zamanTextBox.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
				this.zamanTextBox.Name = "zamanTextBox";
				this.zamanTextBox.Size = new System.Drawing.Size(264, 22);
				this.zamanTextBox.TabIndex = 1;
				// 
				// baslangicDegerGonder
				// 
				this.baslangicDegerGonder.Location = new System.Drawing.Point(544, 484);
				this.baslangicDegerGonder.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
				this.baslangicDegerGonder.Name = "baslangicDegerGonder";
				this.baslangicDegerGonder.Size = new System.Drawing.Size(117, 37);
				this.baslangicDegerGonder.TabIndex = 2;
				this.baslangicDegerGonder.Text = "Saat Gönder";
				this.baslangicDegerGonder.UseVisualStyleBackColor = true;
				this.baslangicDegerGonder.Click += new System.EventHandler(this.BaslangicDegerGonderClick);
				// 
				// zamanTextBox2
				// 
				this.zamanTextBox2.Location = new System.Drawing.Point(235, 556);
				this.zamanTextBox2.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
				this.zamanTextBox2.Name = "zamanTextBox2";
				this.zamanTextBox2.Size = new System.Drawing.Size(264, 22);
				this.zamanTextBox2.TabIndex = 4;
				// 
				// label2
				// 
				this.label2.Location = new System.Drawing.Point(65, 556);
				this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
				this.label2.Name = "label2";
				this.label2.Size = new System.Drawing.Size(144, 21);
				this.label2.TabIndex = 3;
				this.label2.Text = "Gelen Saat";
				// 
				// SaatAl
				// 
				this.SaatAl.Location = new System.Drawing.Point(544, 549);
				this.SaatAl.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
				this.SaatAl.Name = "SaatAl";
				this.SaatAl.Size = new System.Drawing.Size(117, 37);
				this.SaatAl.TabIndex = 5;
				this.SaatAl.Text = "Saat Al";
				this.SaatAl.UseVisualStyleBackColor = true;
				this.SaatAl.Click += new System.EventHandler(this.SaatAlClick);
				// 
				// textBoudrate
				// 
				this.textBoudrate.Location = new System.Drawing.Point(235, 114);
				this.textBoudrate.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
				this.textBoudrate.Name = "textBoudrate";
				this.textBoudrate.Size = new System.Drawing.Size(264, 22);
				this.textBoudrate.TabIndex = 9;
				this.textBoudrate.Text = "9600";
				// 
				// label3
				// 
				this.label3.Location = new System.Drawing.Point(65, 114);
				this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
				this.label3.Name = "label3";
				this.label3.Size = new System.Drawing.Size(144, 21);
				this.label3.TabIndex = 8;
				this.label3.Text = "BoudRate";
				// 
				// textcom
				// 
				this.textcom.Location = new System.Drawing.Point(235, 49);
				this.textcom.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
				this.textcom.Name = "textcom";
				this.textcom.Size = new System.Drawing.Size(264, 22);
				this.textcom.TabIndex = 7;
				this.textcom.Text = "COM10";
				// 
				// label4
				// 
				this.label4.Location = new System.Drawing.Point(65, 49);
				this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
				this.label4.Name = "label4";
				this.label4.Size = new System.Drawing.Size(144, 21);
				this.label4.TabIndex = 6;
				this.label4.Text = "Com NO";
				// 
				// textdatabits
				// 
				this.textdatabits.Location = new System.Drawing.Point(235, 180);
				this.textdatabits.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
				this.textdatabits.Name = "textdatabits";
				this.textdatabits.Size = new System.Drawing.Size(264, 22);
				this.textdatabits.TabIndex = 11;
				this.textdatabits.Text = "8";
				// 
				// label5
				// 
				this.label5.Location = new System.Drawing.Point(65, 180);
				this.label5.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
				this.label5.Name = "label5";
				this.label5.Size = new System.Drawing.Size(144, 21);
				this.label5.TabIndex = 10;
				this.label5.Text = "DataBits";
				// 
				// btnac
				// 
				this.btnac.Location = new System.Drawing.Point(544, 49);
				this.btnac.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
				this.btnac.Name = "btnac";
				this.btnac.Size = new System.Drawing.Size(117, 37);
				this.btnac.TabIndex = 12;
				this.btnac.Text = "Port Aç";
				this.btnac.UseVisualStyleBackColor = true;
				this.btnac.Click += new System.EventHandler(this.BtnacClick);
				// 
				// btnkpt
				// 
				this.btnkpt.Location = new System.Drawing.Point(544, 114);
				this.btnkpt.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
				this.btnkpt.Name = "btnkpt";
				this.btnkpt.Size = new System.Drawing.Size(117, 37);
				this.btnkpt.TabIndex = 13;
				this.btnkpt.Text = "Port Kapat";
				this.btnkpt.UseVisualStyleBackColor = true;
				this.btnkpt.Click += new System.EventHandler(this.BtnkptClick);
				// 
				// textadc
				// 
				this.textadc.Location = new System.Drawing.Point(235, 412);
				this.textadc.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
				this.textadc.Multiline = true;
				this.textadc.Name = "textadc";
				this.textadc.Size = new System.Drawing.Size(225, 32);
				this.textadc.TabIndex = 21;
				// 
				// label6
				// 
				this.label6.Location = new System.Drawing.Point(65, 423);
				this.label6.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
				this.label6.Name = "label6";
				this.label6.Size = new System.Drawing.Size(199, 22);
				this.label6.TabIndex = 20;
				this.label6.Text = "ADC veri";
				// 
				// textBox1
				// 
				this.textBox1.BackColor = System.Drawing.SystemColors.Window;
				this.textBox1.ForeColor = System.Drawing.SystemColors.WindowText;
				this.textBox1.Location = new System.Drawing.Point(235, 322);
				this.textBox1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
				this.textBox1.Multiline = true;
				this.textBox1.Name = "textBox1";
				this.textBox1.Size = new System.Drawing.Size(351, 69);
				this.textBox1.TabIndex = 19;
				// 
				// textgelenveriler
				// 
				this.textgelenveriler.Location = new System.Drawing.Point(65, 350);
				this.textgelenveriler.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
				this.textgelenveriler.Name = "textgelenveriler";
				this.textgelenveriler.Size = new System.Drawing.Size(163, 26);
				this.textgelenveriler.TabIndex = 18;
				this.textgelenveriler.Text = "Gelen Veri";
				// 
				// btngonder
				// 
				this.btngonder.Location = new System.Drawing.Point(469, 234);
				this.btngonder.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
				this.btngonder.Name = "btngonder";
				this.btngonder.Size = new System.Drawing.Size(117, 47);
				this.btngonder.TabIndex = 17;
				this.btngonder.Text = "Gönder";
				this.btngonder.UseVisualStyleBackColor = true;
				this.btngonder.Click += new System.EventHandler(this.BtngonderClick);
				// 
				// textgonderilecekveriler
				// 
				this.textgonderilecekveriler.Location = new System.Drawing.Point(235, 234);
				this.textgonderilecekveriler.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
				this.textgonderilecekveriler.Multiline = true;
				this.textgonderilecekveriler.Name = "textgonderilecekveriler";
				this.textgonderilecekveriler.Size = new System.Drawing.Size(189, 46);
				this.textgonderilecekveriler.TabIndex = 16;
				// 
				// label7
				// 
				this.label7.Location = new System.Drawing.Point(65, 255);
				this.label7.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
				this.label7.Name = "label7";
				this.label7.Size = new System.Drawing.Size(163, 26);
				this.label7.TabIndex = 15;
				this.label7.Text = "Gönderilecek veri";
				// 
				// btnsicaklik
				// 
				this.btnsicaklik.Location = new System.Drawing.Point(544, 412);
				this.btnsicaklik.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
				this.btnsicaklik.Name = "btnsicaklik";
				this.btnsicaklik.Size = new System.Drawing.Size(117, 37);
				this.btnsicaklik.TabIndex = 22;
				this.btnsicaklik.Text = "Sıcaklık Veri Al";
				this.btnsicaklik.UseVisualStyleBackColor = true;
				// 
				// MainForm
				// 
				this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
				this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
				this.ClientSize = new System.Drawing.Size(709, 651);
				this.Controls.Add(this.btnsicaklik);
				this.Controls.Add(this.textadc);
				this.Controls.Add(this.label6);
				this.Controls.Add(this.textBox1);
				this.Controls.Add(this.textgelenveriler);
				this.Controls.Add(this.btngonder);
				this.Controls.Add(this.textgonderilecekveriler);
				this.Controls.Add(this.label7);
				this.Controls.Add(this.btnkpt);
				this.Controls.Add(this.btnac);
				this.Controls.Add(this.textdatabits);
				this.Controls.Add(this.label5);
				this.Controls.Add(this.textBoudrate);
				this.Controls.Add(this.label3);
				this.Controls.Add(this.textcom);
				this.Controls.Add(this.label4);
				this.Controls.Add(this.SaatAl);
				this.Controls.Add(this.zamanTextBox2);
				this.Controls.Add(this.label2);
				this.Controls.Add(this.baslangicDegerGonder);
				this.Controls.Add(this.zamanTextBox);
				this.Controls.Add(this.label1);
				this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
				this.Name = "MainForm";
				this.Text = "LCDSeriPortson";
				this.ResumeLayout(false);
				this.PerformLayout();
			}
		}
	}