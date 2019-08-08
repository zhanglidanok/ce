<template>
    <div>
        <mt-tab-container v-model='active'>
            <mt-tab-container-item id='cart'>
                <cart></cart>
            </mt-tab-container-item>
             <mt-tab-container-item id='product'>
                product
            </mt-tab-container-item>
        </mt-tab-container>
        <mt-tabbar v-model='active' fixed>
            <mt-tab-item id='cart' @click.native="checkedLogin">
                购物车
            </mt-tab-item>
            <mt-tab-item id='product'>
                商品
            </mt-tab-item>
        </mt-tabbar>
    </div>
</template>
<script>
import cart from './cart'
export default {
    data(){
        return{
            active:"product",
            isLogin:0,
        }
    },
    components:{
        cart,
    },
    created(){
       var isLogin=sessionStorage.getItem('uid')
       var rs=null
       if(!isLogin){
           rs=fase
       }else{
           rs=true
       };
       this.isLogin=rs
    },
    methods:{
        checkedLogin(){
           if(!this.isLogin){
               this.$router.push('/login')
           }
        },
    }
}
</script>
