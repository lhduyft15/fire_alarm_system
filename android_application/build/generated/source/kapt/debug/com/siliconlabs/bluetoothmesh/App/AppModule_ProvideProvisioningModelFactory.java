// Generated by Dagger (https://google.github.io/dagger).
package com.siliconlabs.bluetoothmesh.App;

import com.siliconlabs.bluetoothmesh.App.Logic.MeshLogic;
import com.siliconlabs.bluetoothmesh.App.Models.MeshNodeManager;
import com.siliconlabs.bluetoothmesh.App.Models.ProvisioningModel;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import javax.inject.Provider;

public final class AppModule_ProvideProvisioningModelFactory implements Factory<ProvisioningModel> {
  private final AppModule module;

  private final Provider<MeshLogic> meshLogicProvider;

  private final Provider<MeshNodeManager> meshNodeManagerProvider;

  public AppModule_ProvideProvisioningModelFactory(
      AppModule module,
      Provider<MeshLogic> meshLogicProvider,
      Provider<MeshNodeManager> meshNodeManagerProvider) {
    this.module = module;
    this.meshLogicProvider = meshLogicProvider;
    this.meshNodeManagerProvider = meshNodeManagerProvider;
  }

  @Override
  public ProvisioningModel get() {
    return provideInstance(module, meshLogicProvider, meshNodeManagerProvider);
  }

  public static ProvisioningModel provideInstance(
      AppModule module,
      Provider<MeshLogic> meshLogicProvider,
      Provider<MeshNodeManager> meshNodeManagerProvider) {
    return proxyProvideProvisioningModel(
        module, meshLogicProvider.get(), meshNodeManagerProvider.get());
  }

  public static AppModule_ProvideProvisioningModelFactory create(
      AppModule module,
      Provider<MeshLogic> meshLogicProvider,
      Provider<MeshNodeManager> meshNodeManagerProvider) {
    return new AppModule_ProvideProvisioningModelFactory(
        module, meshLogicProvider, meshNodeManagerProvider);
  }

  public static ProvisioningModel proxyProvideProvisioningModel(
      AppModule instance, MeshLogic meshLogic, MeshNodeManager meshNodeManager) {
    return Preconditions.checkNotNull(
        instance.provideProvisioningModel(meshLogic, meshNodeManager),
        "Cannot return null from a non-@Nullable @Provides method");
  }
}