<template>
    <div>
       <my-header> </my-header>
       <router-view></router-view>
    </div>
</template>
<script>
import Header from './header'
export default {
    data(){
        return{
           active:'login',
           m1:"父亲给儿子传递数据",
           m2:""
        }
    },
    created(){
       
    },
    components:{
        'myHeader':Header
    },
    methods:{
       handleEvent(msg){
           console.log(msg,this.active)
           this.m2=msg
       },
    }

}
</script>
<style scoped>

</style>


