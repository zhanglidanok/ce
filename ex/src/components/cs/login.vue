<template>
    <div>
      <div >
       <h2>login</h2>
       <!-- <input type="text" placeholder="请输入用户名">、
       <input type="password" placeholder="请输入密码"> -->
       <mt-field label='用户名'  placeholder="请输入用户名" v-model='uname' ></mt-field>
       <mt-field label='密码' placeholder="请输入密码" v-model="upass"  ></mt-field>
       <mt-button size='large' class='myButton' @click="login">登录</mt-button>
       </div>
      
    </div>
    
</template>
<script>
export default {
    data(){
        return{
           val3:[],
           uname:'',
           upass:''
        }
    },
    created(){
        
    },
    methods:{
        login(){
            var uname=this.uname;
            var upass=this.upass;
            console.log(uname,upass)
            var testUname=/^[a-z]{3,6}$/.test(uname)
            var testUpwd=/^[0-9]{3,8}$/.test(upass)
            if(!testUname){
                this.$toast("用户名错误");return;
            }else if(!upass){
                this.$toast("密码错误");return
            }else{
                var data={uname,upass}
                this.axios.post('login',this.qs.stringify(data)).then(result=>{
                      console.log(result)
                       sessionStorage.setItem('uid',"已登录")
                       console.log(sessionStorage.getItem('uid'))
                       this.$router.push('/')
                })
            }
        },
    }
}
</script>
<style scoped>
   /* @import '../../assets/base.css'; */
   /* .myButton{
       background:black;
   } */
   /* *{
       color:black !important;
   } */
    .mint-button--default{
         background:-webkit-linear-gradient(left,#ff9000,#ff5000) no-repeat;
        color:beige; 
   } 
   /* input{
       display: block;
       border:0;
       border-bottom: 1px solid #ddd;
       outline: 0;
       width:100%;
       height:50px;
       margin-bottom:10px;
   } */
    /* 上面的线隐藏 */
   /* 输入框底边框样式 */
   #d1 .mint-cell-wrapper  {
      border-bottom: 1px solid #ff0 !important;
    }
    
</style>


